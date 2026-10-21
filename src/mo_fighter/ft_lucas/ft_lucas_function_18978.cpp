#pragma force_active on
struct Fn114Source {
    unsigned char prefix[8];
    void* module;
    unsigned char middle[0xcc];
    unsigned char* enumeration;
};
struct Fn114Cast {
    unsigned char prefix[0xc4];
    void* parameters;
    int kind;
};
struct Fn114Pair { void* parameters; void* resources; };
extern "C" {
extern unsigned char lbl_114_data_9E94[];
extern unsigned char lbl_114_data_3184[];
extern unsigned char lbl_114_data_3C7C[];
extern unsigned char g_ftCommonDataAccesser[];
void* __dynamic_cast(void*, int, const void*, const void*, short);
void* fn_27_148F10(void*, int, bool*);
void* fn_114_1A19C(void*, int, const Fn114Pair*, void*);
void* fn_114_18978(void* object, Fn114Source* source) {
    *static_cast<void**>(object) = lbl_114_data_9E94;
    bool flags[2] = { false, false };
    int kind = static_cast<Fn114Cast*>(__dynamic_cast(
        source->module, 0x3c, lbl_114_data_3184, lbl_114_data_3C7C,
        static_cast<short>(1)))->kind;
    void* resources = *reinterpret_cast<void**>(source->enumeration + 0xc0);
    Fn114Pair parameters;
    parameters.parameters = &static_cast<Fn114Cast*>(__dynamic_cast(
        source->module, 0x3c, lbl_114_data_3184, lbl_114_data_3C7C,
        static_cast<short>(1)))->parameters;
    parameters.resources = resources;
    void* common = fn_27_148F10(g_ftCommonDataAccesser, kind, &flags[1]);
    fn_114_1A19C(static_cast<unsigned char*>(object) + 4, 0, &parameters, common);
    return object;
}
}
