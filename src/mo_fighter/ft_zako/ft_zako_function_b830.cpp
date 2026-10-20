#pragma force_active on
struct ZakoClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_126_data_5D98[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(ZakoClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ZakoClassInfo*, int, void*);
}

extern "C" ZakoClassInfo* fn_126_B830(ZakoClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_126_data_5D98;
        info->vtable = lbl_126_data_5D98 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x33, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
