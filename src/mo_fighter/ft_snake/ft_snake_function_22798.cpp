#pragma force_active on
struct SnakeArticleParameterSource {
    unsigned char prefix[8];
    void* module;
    unsigned char middle[0xcc];
    unsigned char* enumeration;
};
struct SnakeArticleParameterCast {
    unsigned char prefix[0xc4];
    void* parameters;
    int kind;
};
struct SnakeArticleParameterPair { void* parameters; void* resources; };
extern "C" {
extern unsigned char lbl_122_data_FE88[];
extern unsigned char lbl_122_data_8154[];
extern unsigned char lbl_122_data_8C98[];
extern unsigned char g_ftCommonDataAccesser[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_27_147FD8(void*, int, bool*);
void* fn_122_23B40(void*, int, const SnakeArticleParameterPair*, void*);
void* fn_122_22798(void* object, SnakeArticleParameterSource* source) {
    *static_cast<void**>(object) = lbl_122_data_FE88;
    bool flags[2] = { false, false };
    int kind = static_cast<SnakeArticleParameterCast*>(__dynamic_cast(
        source->module, 0x3c, lbl_122_data_8154, lbl_122_data_8C98,
        static_cast<short>(1)))->kind;
    void* resources = *reinterpret_cast<void**>(source->enumeration + 0xc0);
    SnakeArticleParameterPair parameters;
    parameters.parameters = &static_cast<SnakeArticleParameterCast*>(__dynamic_cast(
        source->module, 0x3c, lbl_122_data_8154, lbl_122_data_8C98,
        static_cast<short>(1)))->parameters;
    parameters.resources = resources;
    void* common = fn_27_147FD8(g_ftCommonDataAccesser, kind, &flags[1]);
    fn_122_23B40(static_cast<unsigned char*>(object) + 4, 0, &parameters, common);
    return object;
}
}
