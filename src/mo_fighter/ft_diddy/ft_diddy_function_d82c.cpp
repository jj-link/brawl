#pragma force_active on
struct ftClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_115_data_7490[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(ftClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfo*, int, void*);
void __dl__FPv(void*);
}

extern "C" ftClassInfo* fn_115_D82C(ftClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_115_data_7490;
        info->vtable = lbl_115_data_7490 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x1b, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) __dl__FPv(info);
    }
    return info;
}
