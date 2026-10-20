#pragma force_active on
struct WarioClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_110_data_A050[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(WarioClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(WarioClassInfo*, int, void*);
}

extern "C" WarioClassInfo* fn_110_20EB4(WarioClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_110_data_A050;
        info->vtable = lbl_110_data_A050 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x31, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
