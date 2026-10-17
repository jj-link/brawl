// Initializes the PKThunderChild instance holder and its article at object+4.
// Uses the accesser owner and Weapon/StageObject RTTI twice without null checks;
// passes the address of owner slot+C4 and enumeration slot+C0 (heap module),
// together with the common getter result to the original article constructor.
struct NessArticleParameterSource {
    unsigned char prefix[8];
    void* module;
    unsigned char middle[0xcc];
    unsigned char* enumeration;
};
struct NessArticleParameterCast {
    unsigned char prefix[0xc4];
    void* parameters;
    int kind;
};
struct NessArticleParameterPair { void* parameters; void* resources; };
extern "C" {
extern unsigned char lbl_101_data_A58C[];
extern unsigned char lbl_101_data_3838[];
extern unsigned char lbl_101_data_4330[];
extern unsigned char g_ftCommonDataAccesser[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_27_149658(void*, int, bool*);
void* fn_101_1A62C(void*, int, const NessArticleParameterPair*, void*);
void* fn_101_18E28(void* object, NessArticleParameterSource* source) {
    *static_cast<void**>(object) = lbl_101_data_A58C;
    bool flags[2] = { false, false };
    int kind = static_cast<NessArticleParameterCast*>(__dynamic_cast(
        source->module, 0x3c, lbl_101_data_3838, lbl_101_data_4330,
        static_cast<short>(1)))->kind;
    void* resources = *reinterpret_cast<void**>(source->enumeration + 0xc0);
    NessArticleParameterPair parameters;
    parameters.parameters = &static_cast<NessArticleParameterCast*>(__dynamic_cast(
        source->module, 0x3c, lbl_101_data_3838, lbl_101_data_4330,
        static_cast<short>(1)))->parameters;
    parameters.resources = resources;
    void* common = fn_27_149658(g_ftCommonDataAccesser, kind, &flags[1]);
    fn_101_1A62C(static_cast<unsigned char*>(object) + 4, 0, &parameters, common);
    return object;
}
}
