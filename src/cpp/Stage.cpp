#include <Stage.h>
#include <iostream>

using namespace std;

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

	/*Init Uniforms ID*/
	this->ID = new vector<GLint>(8, 0);
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

Projection * Stage::getProjection(){
	return this->projection;
}

void Stage::Notify(string message, void* data){
	if (message == "init VBOs")
		for (int i = 0; i < (int)this->entities.size(); i++)
			this->entities[i]->initGLDataBinding();
	else if (message == "shader id") 
		this->shader_id = *((GLuint*)(&data));
	else if (message == "width/height") {
		this->width = ((float*)data)[0];
		this->height = ((float*)data)[1];
	}
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
	glUniformMatrix4fv(this->ID->at(5), 1, GL_FALSE, &(this->camera->getMatrix())[0][0] );

	this->ID->at(6) = glGetUniformLocation(this->shader_id, "u_projMat");
	glUniformMatrix4fv(this->ID->at(6), 1, GL_FALSE, &(this->projection->getMatrix())[0][0]);

	this->ID->at(7) = glGetUniformLocation(this->shader_id, "u_normalMat");
	glUniformMatrix4fv(this->ID->at(6), 1, GL_FALSE, &( glm::inverse( glm::transpose(this->camera->getMatrix())) )[0][0]);

	/*Render all the entities*/
	for (int i = 0; i < (int)this->entities.size(); i++)
		this->entities[i]->render(this->shader_id);
}
