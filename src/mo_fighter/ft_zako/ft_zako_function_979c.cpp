#pragma force_active on
struct ZakoClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_126_data_52E8[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ZakoClassInfo*, int, void*);
void __dt__11ftClassInfoFv(ZakoClassInfo*, short);
void __dl__FPv(void*);
}

extern "C" ZakoClassInfo* fn_126_979C(ZakoClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_126_data_52E8;
        info->vtable = lbl_126_data_52E8 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x32, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) __dl__FPv(info);
    }
    return info;
}
