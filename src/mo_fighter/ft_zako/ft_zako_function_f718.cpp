#pragma force_active on
struct ZakoClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_126_data_7300[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ZakoClassInfo*, int, void*);
void __dt__11ftClassInfoFv(ZakoClassInfo*, short);
}

extern "C" ZakoClassInfo* fn_126_F718(ZakoClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_126_data_7300;
        info->vtable = lbl_126_data_7300 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x35, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
