#include <Stage.h>

Stage* Stage::uniqueStage = NULL;

Stage::Stage(RenderController* renderController):RenderColleague(renderController){
	/*Init local structures*/
	this->sound = new Sound({"", ""});
	this->skyBox = new SkyBox();
	this->light = new Light();
	this->camera = new Camera();
	this->projection = new Projection();

	/*Init entities*/
	for (int i = 0; i < amountOfPlayers; i++) this->entities.push_back(Player::Instance(NULL, NULL, NULL, i));
	for (int i = 0; i < amountOfEnemies; i++) this->entities.push_back(Enemy::Instance(NULL, NULL, NULL, i));
	for (int i = 0; i < amountOfObjects; i++) this->entities.push_back(Object::Instance(NULL, NULL, NULL, i));

	/*Get shader ID*/
	this->Send("get shader id", NULL);

	/*Init Uniforms ID*/
	this->ID = new vector<GLint>(7, 0);
}

Stage::~Stage(){

}

Stage * Stage::Instance(RenderController * renderController){
	if (!uniqueStage)
		uniqueStage = new Stage(renderController);
	return uniqueStage;
}

void Stage::Destroy(){
	if (!uniqueStage) return;
	uniqueStage->~Stage();
}

void Stage::Notify(string message, void * data){
	if (message == "init VBOs")
		for (int i = 0; i < (int)this->entities.size(); i++)
			this->entities[i]->initGLDataBinding();
	else if (message == "shader id")
		this->shader_id = *((GLuint*)data);
}

void Stage::render(){
	/*Bind ambient light uniforms, projection and view matrices*/
	this->ID->at(0) = glGetUniformLocation(this->shader_id, "u_lightAmbientIntensitys");
	glUniform3f(this->ID->at(0), this->light->getAmbient().r, this->light->getAmbient().g, this->light->getAmbient().b);

	this->ID->at(1) = glGetUniformLocation(this->shader_id, "u_lightDiffuseIntensitys");
	glUniform3f(this->ID->at(1), this->light->getDiffuse().r, this->light->getDiffuse().g, this->light->getDiffuse().b);

	this->ID->at(2) = glGetUniformLocation(this->shader_id, "u_lightSpecularIntensitys");
	glUniform3f(this->ID->at(2), this->light->getSpecular().r, this->light->getSpecular().g, this->light->getSpecular().b);

	this->ID->at(3) = glGetUniformLocation(this->shader_id, "u_lightPosition");
	glUniform3f(this->ID->at(3), this->light->getPosition().x, this->light->getPosition().y, this->light->getPosition().z);

	this->ID->at(4) = glGetUniformLocation(this->shader_id, "eye_position");
	glUniform3f(this->ID->at(4), this->camera->getPosition().x, this->camera->getPosition().y, this->camera->getPosition().z);

	this->ID->at(5) = glGetUniformLocation(this->shader_id, "u_viewMat");
	glUniformMatrix4fv(this->ID->at(5), 1, GL_FALSE, glm::value_ptr(this->camera->getMatrix()) );

	this->ID->at(6) = glGetUniformLocation(this->shader_id, "u_projMat");
	glUniformMatrix4fv(this->ID->at(6), 1, GL_FALSE, glm::value_ptr(this->projection->getMatrix()));

	/*Render all the entities*/
	for (int i = 0; i < (int)this->entities.size(); i++)
		this->entities[i]->render(this->shader_id);
}
