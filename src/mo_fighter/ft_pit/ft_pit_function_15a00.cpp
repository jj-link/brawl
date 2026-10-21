#pragma force_active on
struct PitArticleParameterSource {
    unsigned char prefix[8];
    void* module;
    unsigned char middle[0xcc];
    unsigned char* enumeration;
};
struct PitArticleParameterCast {
    unsigned char prefix[0xc8];
    int kind;
};
struct PitArticleParameterCast2 {
    unsigned char prefix[0xc4];
    void* parameters;
};
struct PitArticleParameterPair { void* parameters; void* resources; };
extern "C" {
extern unsigned char lbl_112_data_9AB8[];
extern unsigned char lbl_112_data_1C94[];
extern unsigned char lbl_112_data_27C4[];
extern unsigned char g_ftCommonDataAccesser[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_27_149194(void*, int, bool*);
void* fn_112_E4D4(void*, void*, const PitArticleParameterPair*, void*);
void* fn_112_15A00(void* object, PitArticleParameterSource* source) {
    *static_cast<void**>(object) = lbl_112_data_9AB8;
    bool flags[2] = { false, false };
    int kind = static_cast<PitArticleParameterCast*>(__dynamic_cast(
        source->module, 0x3c, lbl_112_data_1C94, lbl_112_data_27C4,
        static_cast<short>(1)))->kind;
    void* resources = *reinterpret_cast<void**>(source->enumeration + 0xc0);
    PitArticleParameterPair parameters;
    parameters.parameters = &static_cast<PitArticleParameterCast2*>(__dynamic_cast(
        source->module, 0x3c, lbl_112_data_1C94, lbl_112_data_27C4,
        static_cast<short>(1)))->parameters;
    parameters.resources = resources;
    void* common = fn_27_149194(g_ftCommonDataAccesser, kind, &flags[1]);
    fn_112_E4D4(static_cast<unsigned char*>(object) + 4, 0, &parameters, common);
    return object;
}
}
