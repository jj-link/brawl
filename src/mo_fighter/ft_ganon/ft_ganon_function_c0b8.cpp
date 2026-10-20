#pragma force_active on
struct GanonClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_109_data_6110[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(GanonClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(GanonClassInfo*, int, void*);
}

extern "C" GanonClassInfo* fn_109_C0B8(GanonClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_109_data_6110;
        info->vtable = lbl_109_data_6110 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x14, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
