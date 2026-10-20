#pragma force_active on
struct Ft107ClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_107_data_8CF0[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(Ft107ClassInfo*, int, void*);
void __dt__11ftClassInfoFv(Ft107ClassInfo*, short);
void __dl__FPv(void*);
}

extern "C" Ft107ClassInfo* fn_107_FEA0(Ft107ClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_107_data_8CF0;
        info->vtable = lbl_107_data_8CF0 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x12, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
