struct MarioArticleParameterSource {
    unsigned char prefix[8];
    void* module;
    unsigned char middle[0xcc];
    unsigned char* enumeration;
};
struct MarioArticleParameterCast {
    unsigned char prefix[0xc4];
    void* parameters;
    int kind;
};
struct MarioArticleParameterPair { void* parameters; void* resources; };
extern "C" {
extern unsigned char lbl_91_data_8F2C[];
extern unsigned char lbl_91_data_28A4[];
extern unsigned char lbl_91_data_33D4[];
extern unsigned char g_ftCommonDataAccesser[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_27_147D64(void*, int, bool*);
void* fn_91_1452C(void*, int, const MarioArticleParameterPair*, void*);
void* fn_91_13118(void* object, MarioArticleParameterSource* source) {
    *static_cast<void**>(object) = lbl_91_data_8F2C;
    bool flags[2] = { false, false };
    int kind = static_cast<MarioArticleParameterCast*>(__dynamic_cast(source->module, 0x3c, lbl_91_data_28A4, lbl_91_data_33D4, static_cast<short>(1)))->kind;
    void* resources = *reinterpret_cast<void**>(source->enumeration + 0xc0);
    MarioArticleParameterPair parameters;
    parameters.parameters = &static_cast<MarioArticleParameterCast*>(__dynamic_cast(source->module, 0x3c, lbl_91_data_28A4, lbl_91_data_33D4, static_cast<short>(1)))->parameters;
    parameters.resources = resources;
    void* common = fn_27_147D64(g_ftCommonDataAccesser, kind, &flags[1]);
    fn_91_1452C(static_cast<unsigned char*>(object) + 4, 0, &parameters, common);
    return object;
}
}
