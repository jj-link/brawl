#pragma force_active on
struct ZeldaClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_104_data_C26C[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(ZeldaClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ZeldaClassInfo*, int, void*);
void __dl__FPv(void*);
}

extern "C" ZeldaClassInfo* fn_104_1D8A0(ZeldaClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_104_data_C26C;
        info->vtable = lbl_104_data_C26C + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0xe, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
