#pragma force_active on
struct SonicClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_123_data_6460[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(SonicClassInfo*, int, void*);
void __dt__11ftClassInfoFv(SonicClassInfo*, short);
void __dl__FPv(void*);
}

extern "C" SonicClassInfo* fn_123_EE44(SonicClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_123_data_6460;
        info->vtable = lbl_123_data_6460 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x2f, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
