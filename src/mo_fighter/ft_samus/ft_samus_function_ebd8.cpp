#pragma force_active on
struct SamusClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_94_data_9850[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(SamusClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(SamusClassInfo*, int, void*);
}

extern "C" SamusClassInfo* fn_94_EBD8(SamusClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_94_data_9850;
        info->vtable = lbl_94_data_9850 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 3, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
