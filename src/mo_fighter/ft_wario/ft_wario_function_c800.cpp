#pragma force_active on
struct WarioClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_110_data_60E4[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(WarioClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(WarioClassInfo*, int, void*);
}

extern "C" WarioClassInfo* fn_110_C800(WarioClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_110_data_60E4;
        info->vtable = lbl_110_data_60E4 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x15, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
