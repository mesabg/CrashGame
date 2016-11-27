

#define FARDATA
#define PNGAPI
#define PNG_1_2_X
#define PNG_ASSEMBLER_CODE_SUPPORTED
#define PNG_EASY_ACCESS_SUPPORTED
#define PNG_ERROR_NUMBERS_SUPPORTED
#define PNG_FIXED_POINT_SUPPORTED
#define PNG_FLOATING_POINT_SUPPORTED
#define PNG_FREE_ME_SUPPORTED
#define PNG_HANDLE_AS_UNKNOWN_SUPPORTED
#define PNG_IMPEXP
#define PNG_INFO_IMAGE_SUPPORTED
#define PNG_MMX_CODE_SUPPORTED
#define PNG_MNG_FEATURES_SUPPORTED
#define PNG_NO_READ_iTXt
#define PNG_NO_WRITE_iTXt
#define PNG_PROGRESSIVE_READ_SUPPORTED
#define PNG_READ_16_TO_8_SUPPORTED
#define PNG_READ_ANCILLARY_CHUNKS_SUPPORTED
#define PNG_READ_BACKGROUND_SUPPORTED
#define PNG_READ_BGR_SUPPORTED
#define PNG_READ_COMPOSITE_NODIV_SUPPORTED
#define PNG_READ_DITHER_SUPPORTED
#define PNG_READ_EMPTY_PLTE_SUPPORTED
#define PNG_READ_EXPAND_SUPPORTED
#define PNG_READ_FILLER_SUPPORTED
#define PNG_READ_GAMMA_SUPPORTED
#define PNG_READ_GRAY_TO_RGB_SUPPORTED
#define PNG_READ_INTERLACING_SUPPORTED
#define PNG_READ_INVERT_ALPHA_SUPPORTED
#define PNG_READ_INVERT_SUPPORTED
#define PNG_READ_OPT_PLTE_SUPPORTED
#define PNG_READ_PACKSWAP_SUPPORTED
#define PNG_READ_PACK_SUPPORTED
#define PNG_READ_RGB_TO_GRAY_SUPPORTED
#define PNG_READ_SHIFT_SUPPORTED
#define PNG_READ_STRIP_ALPHA_SUPPORTED
#define PNG_READ_SUPPORTED
#define PNG_READ_SWAP_ALPHA_SUPPORTED
#define PNG_READ_SWAP_SUPPORTED
#define PNG_READ_TEXT_SUPPORTED
#define PNG_READ_TRANSFORMS_SUPPORTED
#define PNG_READ_UNKNOWN_CHUNKS_SUPPORTED
#define PNG_READ_USER_CHUNKS_SUPPORTED
#define PNG_READ_USER_TRANSFORM_SUPPORTED
#define PNG_READ_bKGD_SUPPORTED
#define PNG_READ_cHRM_SUPPORTED
#define PNG_READ_gAMA_SUPPORTED
#define PNG_READ_hIST_SUPPORTED
#define PNG_READ_iCCP_SUPPORTED
#define PNG_READ_oFFs_SUPPORTED
#define PNG_READ_pCAL_SUPPORTED
#define PNG_READ_pHYs_SUPPORTED
#define PNG_READ_sBIT_SUPPORTED
#define PNG_READ_sCAL_SUPPORTED
#define PNG_READ_sPLT_SUPPORTED
#define PNG_READ_sRGB_SUPPORTED
#define PNG_READ_tEXt_SUPPORTED
#define PNG_READ_tIME_SUPPORTED
#define PNG_READ_tRNS_SUPPORTED
#define PNG_READ_zTXt_SUPPORTED
#define PNG_SETJMP_SUPPORTED
#define PNG_SET_USER_LIMITS_SUPPORTED
#define PNG_TEXT_SUPPORTED
#define PNG_TIME_RFC1123_SUPPORTED
#define PNG_UNKNOWN_CHUNKS_SUPPORTED
#define PNG_USER_CHUNKS_SUPPORTED
#define PNG_USER_MEM_SUPPORTED
#define PNG_USER_TRANSFORM_PTR_SUPPORTED
#define PNG_USE_GLOBAL_ARRAYS
#define PNG_WRITE_ANCILLARY_CHUNKS_SUPPORTED
#define PNG_WRITE_BGR_SUPPORTED
#define PNG_WRITE_EMPTY_PLTE_SUPPORTED
#define PNG_WRITE_FILLER_SUPPORTED
#define PNG_WRITE_FLUSH_SUPPORTED
#define PNG_WRITE_INTERLACING_SUPPORTED
#define PNG_WRITE_INVERT_ALPHA_SUPPORTED
#define PNG_WRITE_INVERT_SUPPORTED
#define PNG_WRITE_PACKSWAP_SUPPORTED
#define PNG_WRITE_PACK_SUPPORTED
#define PNG_WRITE_SHIFT_SUPPORTED
#define PNG_WRITE_SUPPORTED
#define PNG_WRITE_SWAP_ALPHA_SUPPORTED
#define PNG_WRITE_SWAP_SUPPORTED
#define PNG_WRITE_TEXT_SUPPORTED
#define PNG_WRITE_TRANSFORMS_SUPPORTED
#define PNG_WRITE_UNKNOWN_CHUNKS_SUPPORTED
#define PNG_WRITE_USER_TRANSFORM_SUPPORTED
#define PNG_WRITE_WEIGHTED_FILTER_SUPPORTED
#define PNG_WRITE_bKGD_SUPPORTED
#define PNG_WRITE_cHRM_SUPPORTED
#define PNG_WRITE_gAMA_SUPPORTED
#define PNG_WRITE_hIST_SUPPORTED
#define PNG_WRITE_iCCP_SUPPORTED
#define PNG_WRITE_oFFs_SUPPORTED
#define PNG_WRITE_pCAL_SUPPORTED
#define PNG_WRITE_pHYs_SUPPORTED
#define PNG_WRITE_sBIT_SUPPORTED
#define PNG_WRITE_sCAL_SUPPORTED
#define PNG_WRITE_sPLT_SUPPORTED
#define PNG_WRITE_sRGB_SUPPORTED
#define PNG_WRITE_tEXt_SUPPORTED
#define PNG_WRITE_tIME_SUPPORTED
#define PNG_WRITE_tRNS_SUPPORTED
#define PNG_WRITE_zTXt_SUPPORTED
#define PNG_bKGD_SUPPORTED
#define PNG_cHRM_SUPPORTED
#define PNG_gAMA_SUPPORTED
#define PNG_hIST_SUPPORTED
#define PNG_iCCP_SUPPORTED
#define PNG_oFFs_SUPPORTED
#define PNG_pCAL_SUPPORTED
#define PNG_pHYs_SUPPORTED
#define PNG_sBIT_SUPPORTED
#define PNG_sCAL_SUPPORTED
#define PNG_sPLT_SUPPORTED
#define PNG_sRGB_SUPPORTED
#define PNG_tEXt_SUPPORTED
#define PNG_tIME_SUPPORTED
#define PNG_tRNS_SUPPORTED
#define PNG_zTXt_SUPPORTED
#define PNG_HEADER_VERSION_STRING   " libpng version 1.2.8 - December 3, 2004 (header)\n"
#define PNG_MMX_READ_FLAGS   \
    ( PNG_ASM_FLAG_MMX_READ_COMBINE_ROW | PNG_ASM_FLAG_MMX_READ_INTERLACE \
    | PNG_ASM_FLAG_MMX_READ_FILTER_SUB | PNG_ASM_FLAG_MMX_READ_FILTER_UP | \
    PNG_ASM_FLAG_MMX_READ_FILTER_AVG | PNG_ASM_FLAG_MMX_READ_FILTER_PAETH \
    )
#define PNG_MMX_FLAGS    \
    ( PNG_ASM_FLAG_MMX_SUPPORT_COMPILED | PNG_ASM_FLAG_MMX_SUPPORT_IN_CPU \
    | PNG_MMX_READ_FLAGS | PNG_MMX_WRITE_FLAGS )
#define PNG_COLOR_TYPE_RGB_ALPHA     \
    (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_ALPHA)
#define PNG_COLOR_TYPE_PALETTE   \
    (PNG_COLOR_MASK_COLOR | PNG_COLOR_MASK_PALETTE)
#define PNG_ALL_FILTERS  \
    (PNG_FILTER_NONE | PNG_FILTER_SUB | PNG_FILTER_UP | PNG_FILTER_AVG | \
    PNG_FILTER_PAETH)
#define png_info_init(info_ptr)  \
    png_info_init_3(&info_ptr, png_sizeof(png_info));
#define png_composite(composite,fg,alpha,bg)     \
    { png_uint_16 temp = (png_uint_16)((png_uint_16)(fg) * \
    (png_uint_16)(alpha) + (png_uint_16)(bg)*(png_uint_16)(255 - \
    (png_uint_16)(alpha)) + (png_uint_16)128); (composite) = \
    (png_byte)((temp + (temp >> 8)) >> 8); }
#define png_composite_16(composite,fg,alpha,bg)  \
    { png_uint_32 temp = (png_uint_32)((png_uint_32)(fg) * \
    (png_uint_32)(alpha) + (png_uint_32)(bg)*(png_uint_32)(65535L - \
    (png_uint_32)(alpha)) + (png_uint_32)32768L); (composite) = \
    (png_uint_16)((temp + (temp >> 16)) >> 16); }
#define PNG_MMX_WRITE_FLAGS ( 0 )
#define PNG_SIZE_MAX    ((png_size_t)(-1))
#define PNG_UINT_32_MAX ((png_uint_32)(-1))
#define PNG_UINT_31_MAX ((png_uint_32)0x7fffffffL)
#define int_p_NULL  (int *)NULL
#define png_bytep_NULL  (png_bytep)NULL
#define png_bytepp_NULL (png_bytepp)NULL
#define PNG_COLOR_TYPE_GRAY_ALPHA   (PNG_COLOR_MASK_ALPHA)
#define PNG_COLOR_TYPE_RGB  (PNG_COLOR_MASK_COLOR)
#define png_doublep_NULL    (png_doublep)NULL
#define png_error_ptr_NULL  (png_error_ptr)NULL
#define png_flush_ptr_NULL  (png_flush_ptr)NULL
#define png_infopp_NULL (png_infopp)NULL
#define png_rw_ptr_NULL (png_rw_ptr)NULL
#define png_structp_NULL    (png_structp)NULL
#define png_uint_16p_NULL   (png_uint_16p)NULL
#define png_voidp_NULL  (png_voidp)NULL
#define CVT_PTR(ptr)    (ptr)
#define CVT_PTR_NOCHECK(ptr)    (ptr)
#define PNG_TEXT_COMPRESSION_NONE   -1
#define PNG_TEXT_COMPRESSION_zTXt_WR    -2
#define PNG_TEXT_COMPRESSION_NONE_WR    -3
#define PNG_BACKGROUND_GAMMA_UNKNOWN    0
#define PNG_COLOR_TYPE_GRAY 0
#define PNG_COMPRESSION_TYPE_BASE   0
#define PNG_CRC_DEFAULT 0
#define PNG_EQUATION_LINEAR 0
#define PNG_FILLER_BEFORE   0
#define PNG_FILTER_HEURISTIC_DEFAULT    0
#define PNG_FILTER_TYPE_BASE    0
#define PNG_FILTER_VALUE_NONE   0
#define PNG_HANDLE_CHUNK_AS_DEFAULT 0
#define PNG_INTERLACE_NONE  0
#define PNG_LIBPNG_VER_BUILD    0
#define PNG_LIBPNG_VER_SONUM    0
#define PNG_OFFSET_PIXEL    0
#define PNG_RESOLUTION_UNKNOWN  0
#define PNG_SCALE_UNKNOWN   0
#define PNG_TEXT_COMPRESSION_zTXt   0
#define PNG_sRGB_INTENT_PERCEPTUAL  0
#define PNG_NO_FILTERS  0x00
#define PNG_TRANSFORM_IDENTITY  0x0000
#define PNG_INFO_gAMA   0x0001
#define PNG_TRANSFORM_STRIP_16  0x0001
#define PNG_INFO_sBIT   0x0002
#define PNG_TRANSFORM_STRIP_ALPHA   0x0002
#define PNG_INFO_cHRM   0x0004
#define PNG_TRANSFORM_PACKING   0x0004
#define PNG_FREE_HIST   0x0008
#define PNG_INFO_PLTE   0x0008
#define PNG_TRANSFORM_PACKSWAP  0x0008
#define PNG_FREE_ICCP   0x0010
#define PNG_INFO_tRNS   0x0010
#define PNG_TRANSFORM_EXPAND    0x0010
#define PNG_FREE_SPLT   0x0020
#define PNG_INFO_bKGD   0x0020
#define PNG_TRANSFORM_INVERT_MONO   0x0020
#define PNG_FREE_ROWS   0x0040
#define PNG_INFO_hIST   0x0040
#define PNG_TRANSFORM_SHIFT 0x0040
#define PNG_FREE_PCAL   0x0080
#define PNG_INFO_pHYs   0x0080
#define PNG_TRANSFORM_BGR   0x0080
#define PNG_ASM_FLAG_MMX_SUPPORT_COMPILED   0x01
#define PNG_FLAG_MNG_EMPTY_PLTE 0x01
#define PNG_FREE_SCAL   0x0100
#define PNG_INFO_oFFs   0x0100
#define PNG_TRANSFORM_SWAP_ALPHA    0x0100
#define PNG_ASM_FLAG_MMX_SUPPORT_IN_CPU 0x02
#define PNG_FREE_UNKN   0x0200
#define PNG_INFO_tIME   0x0200
#define PNG_TRANSFORM_SWAP_ENDIAN   0x0200
#define PNG_ASM_FLAG_MMX_READ_COMBINE_ROW   0x04
#define PNG_FLAG_MNG_FILTER_64  0x04
#define PNG_FREE_LIST   0x0400
#define PNG_INFO_pCAL   0x0400
#define PNG_TRANSFORM_INVERT_ALPHA  0x0400
#define PNG_ALL_MNG_FEATURES    0x05
#define PNG_ASM_FLAG_MMX_READ_INTERLACE 0x08
#define PNG_FILTER_NONE 0x08
#define PNG_INFO_sRGB   0x0800
#define PNG_TRANSFORM_STRIP_FILLER  0x0800
#define PNG_ASM_FLAG_MMX_READ_FILTER_SUB    0x10
#define PNG_FILTER_SUB  0x10
#define PNG_FREE_PLTE   0x1000
#define PNG_INFO_iCCP   0x1000
#define PNG_ASM_FLAG_MMX_READ_FILTER_UP 0x20
#define PNG_FILTER_UP   0x20
#define PNG_FREE_TRNS   0x2000
#define PNG_INFO_sPLT   0x2000
#define PNG_ASM_FLAG_MMX_READ_FILTER_AVG    0x40
#define PNG_FILTER_AVG  0x40
#define PNG_FREE_TEXT   0x4000
#define PNG_INFO_sCAL   0x4000
#define PNG_FREE_MUL    0x4220
#define PNG_FREE_ALL    0x7fff
#define PNG_ASM_FLAG_MMX_READ_FILTER_PAETH  0x80
#define PNG_FILTER_PAETH    0x80
#define PNG_ASM_FLAGS_INITIALIZED   0x80000000
#define PNG_INFO_IDAT   0x8000L
#define PNG_BACKGROUND_GAMMA_SCREEN 1
#define PNG_COLOR_MASK_PALETTE  1
#define PNG_CRC_ERROR_QUIT  1
#define PNG_DESTROY_WILL_FREE_DATA  1
#define PNG_EQUATION_BASE_E 1
#define PNG_FILLER_AFTER    1
#define PNG_FILTER_HEURISTIC_UNWEIGHTED 1
#define PNG_FILTER_VALUE_SUB    1
#define PNG_HANDLE_CHUNK_NEVER  1
#define PNG_INTERLACE_ADAM7 1
#define PNG_ITXT_COMPRESSION_NONE   1
#define PNG_LIBPNG_BUILD_ALPHA  1
#define PNG_LIBPNG_VER_MAJOR    1
#define PNG_OFFSET_MICROMETER   1
#define PNG_RESOLUTION_METER    1
#define PNG_SCALE_METER 1
#define PNG_SELECT_READ 1
#define PNG_SET_WILL_FREE_DATA  1
#define PNG_sRGB_INTENT_RELATIVE    1
#define PNG_LIBPNG_VER_STRING   "1.2.8"
#define PNG_USER_HEIGHT_MAX 1000000L
#define PNG_USER_WIDTH_MAX  1000000L
#define PNG_LIBPNG_VER  10208
#define PNG_LIBPNG_VER_DLLNUM   13
#define PNG_LIBPNG_BUILD_PRIVATE    16
#define PNG_BACKGROUND_GAMMA_FILE   2
#define PNG_COLOR_MASK_COLOR    2
#define PNG_CRC_WARN_DISCARD    2
#define PNG_EQUATION_ARBITRARY  2
#define PNG_FILTER_HEURISTIC_WEIGHTED   2
#define PNG_FILTER_VALUE_UP 2
#define PNG_HANDLE_CHUNK_IF_SAFE    2
#define PNG_INTERLACE_LAST  2
#define PNG_ITXT_COMPRESSION_zTXt   2
#define PNG_LIBPNG_BUILD_BETA   2
#define PNG_LIBPNG_VER_MINOR    2
#define PNG_OFFSET_LAST 2
#define PNG_RESOLUTION_LAST 2
#define PNG_SCALE_RADIAN    2
#define PNG_SELECT_WRITE    2
#define PNG_USER_WILL_FREE_DATA 2
#define PNG_sRGB_INTENT_SATURATION  2
#define PNG_MAX_PALETTE_LENGTH  256
#define PNG_BACKGROUND_GAMMA_UNIQUE 3
#define PNG_CRC_WARN_USE    3
#define PNG_EQUATION_HYPERBOLIC 3
#define PNG_FILTER_HEURISTIC_LAST   3
#define PNG_FILTER_VALUE_AVG    3
#define PNG_HANDLE_CHUNK_ALWAYS 3
#define PNG_LIBPNG_BUILD_RC 3
#define PNG_SCALE_LAST  3
#define PNG_TEXT_COMPRESSION_LAST   3
#define PNG_sRGB_INTENT_ABSOLUTE    3
#define PNG_LIBPNG_BUILD_SPECIAL    32
#define PNG_COLOR_MASK_ALPHA    4
#define PNG_CRC_QUIET_USE   4
#define PNG_EQUATION_LAST   4
#define PNG_FILTER_VALUE_PAETH  4
#define PNG_LIBPNG_BUILD_STABLE 4
#define PNG_sRGB_INTENT_LAST    4
#define PNG_CRC_NO_CHANGE   5
#define PNG_FILTER_VALUE_LAST   5
#define PNG_INTRAPIXEL_DIFFERENCING 64
#define PNG_LIBPNG_BUILD_RELEASE_STATUS_MASK    7
#define PNG_KEYWORD_MAX_LENGTH  79
#define PNG_LIBPNG_BUILD_PATCH  8
#define PNG_LIBPNG_VER_RELEASE  8
#define PNG_ZBUF_SIZE   8192
#define PNG_ABORT() abort()
#define PNG_CONST   const
#define PNG_EXPORT_VAR(type)    extern PNG_IMPEXP type
#define png_memcmp  memcmp
#define png_memcpy  memcpy
#define png_memset  memset
#define PNGARG(arglist) OF(arglist)
#define PNG_COLOR_TYPE_GA   PNG_COLOR_TYPE_GRAY_ALPHA
#define PNG_COLOR_TYPE_RGBA PNG_COLOR_TYPE_RGB_ALPHA
#define PNG_COMPRESSION_TYPE_DEFAULT    PNG_COMPRESSION_TYPE_BASE
#define PNG_FILTER_TYPE_DEFAULT PNG_FILTER_TYPE_BASE
#define PNG_EXPORT(type,symbol) PNG_IMPEXP type PNGAPI symbol
#define PNG_LIBPNG_BUILD_TYPE   PNG_LIBPNG_BUILD_BASE_TYPE
#define PNG_LIBPNG_BUILD_BASE_TYPE  PNG_LIBPNG_BUILD_STABLE
#define PNG_MAX_UINT    PNG_UINT_31_MAX
#define png_sizeof(x)   sizeof (x)
#define png_strcpy  strcpy
#define png_strlen  strlen
#define png_strncpy strncpy

typedef struct png_struct_def
 png_struct;
typedef png_struct *png_structp;
typedef struct png_info_struct
 png_info;
typedef png_info *png_infop;
typedef void *png_voidp;
typedef void (*png_progressive_info_ptr) (png_structp, png_infop);
typedef unsigned char png_byte;
typedef png_byte *png_bytep;
typedef unsigned long int png_uint_32;
typedef void (*png_progressive_row_ptr) (png_structp, png_bytep,
                     png_uint_32, int);
typedef void (*png_progressive_end_ptr) (png_structp, png_infop);
typedef struct png_color_8_struct {
    png_byte red;
    png_byte green;
    png_byte blue;
    png_byte gray;
    png_byte alpha;
} png_color_8;
typedef png_color_8 *png_color_8p;
typedef long int png_int_32;
typedef char *png_charp;
typedef size_t png_size_t;
typedef struct png_text_struct {
    int compression;
    png_charp key;
    png_charp text;
    png_size_t text_length;
} png_text;
typedef png_text *png_textp;
typedef png_byte **png_bytepp;
typedef unsigned short png_uint_16;
typedef struct png_color_16_struct {
    png_byte index;
    png_uint_16 red;
    png_uint_16 green;
    png_uint_16 blue;
    png_uint_16 gray;
} png_color_16;
typedef png_color_16 *png_color_16p;
typedef struct png_color_struct {
    png_byte red;
    png_byte green;
    png_byte blue;
} png_color;
typedef png_color *png_colorp;
typedef const char *png_const_charp;
typedef void (*png_error_ptr) (png_structp, png_const_charp);
typedef void (*png_rw_ptr) (png_structp, png_bytep, png_size_t);
typedef struct png_time_struct {
    png_uint_16 year;
    png_byte month;
    png_byte day;
    png_byte hour;
    png_byte minute;
    png_byte second;
} png_time;
typedef png_time *png_timep;
typedef png_uint_16 *png_uint_16p;
typedef void (*png_flush_ptr) (png_structp);
typedef char **png_charpp;
typedef png_struct **png_structpp;
typedef png_info **png_infopp;
typedef FILE *png_FILE_p;
typedef struct png_row_info_struct {
    png_uint_32 width;
    png_uint_32 rowbytes;
    png_byte color_type;
    png_byte bit_depth;
    png_byte channels;
    png_byte pixel_depth;
} png_row_info;
typedef png_row_info *png_row_infop;
typedef png_structp version_1_2_8;
typedef png_uint_32 *png_uint_32p;
typedef png_uint_16 **png_uint_16pp;
typedef png_int_32 png_fixed_point;
typedef double *png_doublep;
//typedef charf *png_zcharp;
typedef png_fixed_point *png_fixed_point_p;
typedef png_int_32 *png_int_32p;
//typedef z_stream *png_zstreamp;
typedef short png_int_16;
typedef png_int_16 *png_int_16p;
typedef png_int_16 **png_int_16pp;
typedef png_int_32 **png_int_32pp;
typedef png_uint_32 **png_uint_32pp;
//typedef charf **png_zcharpp;
typedef char ***png_charppp;
typedef const char **png_const_charpp;
typedef double **png_doublepp;
typedef png_colorp *png_colorpp;
typedef png_color_16p *png_color_16pp;
typedef png_color_8p *png_color_8pp;
typedef png_fixed_point **png_fixed_point_pp;
typedef png_row_info **png_row_infopp;
typedef png_textp *png_textpp;
typedef png_timep *png_timepp;
extern void png_set_gAMA(png_structp, png_infop, double);
extern void png_set_progressive_read_fn(png_structp, png_voidp,
                    png_progressive_info_ptr,
                    png_progressive_row_ptr,
                    png_progressive_end_ptr);
extern void png_set_shift(png_structp, png_color_8p);
extern png_byte png_get_interlace_type(png_structp, png_infop);
extern void png_read_info(png_structp, png_infop);
extern png_uint_32 png_get_image_height(png_structp, png_infop);
extern png_int_32 png_get_y_offset_pixels(png_structp, png_infop);
extern png_charp png_get_libpng_ver(png_structp);
extern void png_set_packswap(png_structp);
extern png_uint_32 png_get_sBIT(png_structp, png_infop, png_color_8p *);
extern void png_process_data(png_structp, png_infop, png_bytep,
                 png_size_t);
extern png_uint_32 png_get_text(png_structp, png_infop, png_textp *,
                int *);
extern void png_write_rows(png_structp, png_bytepp, png_uint_32);
extern const char png_libpng_ver[];
extern png_uint_32 png_access_version_number(void);
extern png_voidp png_get_progressive_ptr(png_structp);
extern png_uint_32 png_get_rowbytes(png_structp, png_infop);
extern void png_write_flush(png_structp);
extern void png_set_tRNS(png_structp, png_infop, png_bytep, int,
             png_color_16p);
extern png_uint_32 png_get_x_pixels_per_meter(png_structp, png_infop);
extern png_int_32 png_get_x_offset_pixels(png_structp, png_infop);
extern png_uint_32 png_get_sRGB(png_structp, png_infop, int *);
extern png_byte png_get_color_type(png_structp, png_infop);
extern png_uint_32 png_get_IHDR(png_structp, png_infop, png_uint_32 *,
                png_uint_32 *, int *, int *, int *, int *,
                int *);
extern png_uint_32 png_get_PLTE(png_structp, png_infop, png_colorp *,
                int *);
extern void png_set_filter(png_structp, int, int);
extern png_uint_32 png_get_pHYs(png_structp, png_infop, png_uint_32 *,
                png_uint_32 *, int *);
extern png_uint_32 png_get_image_width(png_structp, png_infop);
extern void png_set_strip_16(png_structp);
extern void png_set_bKGD(png_structp, png_infop, png_color_16p);
extern png_uint_32 png_get_y_pixels_per_meter(png_structp, png_infop);
extern void png_write_png(png_structp, png_infop, int, void*);
extern void png_set_error_fn(png_structp, png_voidp, png_error_ptr,
                 png_error_ptr);
extern void png_set_sBIT(png_structp, png_infop, png_color_8p);
extern void png_error(png_structp, png_const_charp);
extern void png_set_read_fn(png_structp, png_voidp, png_rw_ptr);
extern int png_sig_cmp(png_bytep, png_size_t, png_size_t);
extern png_uint_32 png_get_tIME(png_structp, png_infop, png_timep *);
extern void png_set_pHYs(png_structp, png_infop, png_uint_32, png_uint_32,
             int);
extern png_byte png_get_bit_depth(png_structp, png_infop);
extern void png_free(png_structp, png_voidp);
extern void png_set_rgb_to_gray(png_structp, int, double, double);
extern void png_set_hIST(png_structp, png_infop, png_uint_16p);
extern png_uint_32 png_get_cHRM(png_structp, png_infop, double *, double *,
                double *, double *, double *, double *,
                double *, double *);
extern void png_set_filler(png_structp, png_uint_32, int);
extern void png_set_text(png_structp, png_infop, png_textp, int);
extern void png_set_cHRM(png_structp, png_infop, double, double, double,
             double, double, double, double, double);
extern void png_set_gray_to_rgb(png_structp);
extern png_uint_32 png_get_bKGD(png_structp, png_infop, png_color_16p *);
extern void png_read_end(png_structp, png_infop);
extern png_byte png_get_channels(png_structp, png_infop);
extern void png_warning(png_structp, png_const_charp);
extern void png_set_write_fn(png_structp, png_voidp, png_rw_ptr,
                 png_flush_ptr);
extern void png_set_tIME(png_structp, png_infop, png_timep);
extern png_structp png_create_read_struct(png_const_charp, png_voidp,
                      png_error_ptr, png_error_ptr);
extern void png_read_update_info(png_structp, png_infop);
extern png_infop png_create_info_struct(png_structp);
extern png_uint_32 png_get_hIST(png_structp, png_infop, png_uint_16p *);
extern void png_set_sRGB(png_structp, png_infop, int);
extern png_uint_32 png_get_iCCP(png_structp, png_infop, png_charpp, int *,
                png_charpp, png_uint_32 *);
extern png_uint_32 png_get_gAMA(png_structp, png_infop, double *);
extern png_uint_32 png_get_valid(png_structp, png_infop, png_uint_32);
extern void png_set_compression_level(png_structp, int);
extern void png_set_packing(png_structp);
extern void png_write_image(png_structp, png_bytepp);
extern void png_write_end(png_structp, png_infop);
extern int png_set_interlace_handling(png_structp);
extern png_bytepp png_get_rows(png_structp, png_infop);
extern void png_progressive_combine_row(png_structp, png_bytep, png_bytep);
extern void png_set_bgr(png_structp);
extern void png_set_dither(png_structp, png_colorp, int, int, png_uint_16p,
               int);
extern void png_set_rows(png_structp, png_infop, png_bytepp);
extern png_voidp png_malloc(png_structp, png_uint_32);
extern void png_write_row(png_structp, png_bytep);
extern void png_set_sig_bytes(png_structp, int);
extern png_uint_32 png_get_tRNS(png_structp, png_infop, png_bytep *, int *,
                png_color_16p *);
extern void png_write_chunk(png_structp, png_bytep, png_bytep, png_size_t);
extern void png_write_info(png_structp, png_infop);
extern void png_set_IHDR(png_structp, png_infop, png_uint_32, png_uint_32,
             int, int, int, int, int);
extern void png_set_invert_mono(png_structp);
extern png_structp png_create_write_struct(png_const_charp, png_voidp,
                       png_error_ptr, png_error_ptr);
extern void png_read_png(png_structp, png_infop, int, void*);
extern void png_read_rows(png_structp, png_bytepp, png_bytepp,
              png_uint_32);
extern void png_read_row(png_structp, png_bytep, png_bytep);
extern void png_destroy_write_struct(png_structpp, png_infopp);
extern void png_set_swap_alpha(png_structp);
extern void png_destroy_read_struct(png_structpp, png_infopp, png_infopp);
extern png_voidp png_get_io_ptr(png_structp);
extern png_uint_32 png_get_oFFs(png_structp, png_infop, png_int_32 *,
                png_int_32 *, int *);
extern void png_set_strip_alpha(png_structp);
extern void png_set_background(png_structp, png_color_16p, int, int,
                   double);
extern void png_set_iCCP(png_structp, png_infop, png_charp, int, png_charp,
             png_uint_32);
extern void png_init_io(png_structp, png_FILE_p);
extern void png_set_PLTE(png_structp, png_infop, png_colorp, int);
extern png_voidp png_get_error_ptr(png_structp);
extern void png_set_gamma(png_structp, double, double);
extern void png_set_swap(png_structp);
extern void png_read_image(png_structp, png_bytepp);
extern void png_set_expand(png_structp);
extern void png_set_oFFs(png_structp, png_infop, png_int_32, png_int_32,
             int);