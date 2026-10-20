#pragma force_active on
struct FtClassInfo125 {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_125_data_72B0[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfo125*, int, void*);
void __dt__11ftClassInfoFv(FtClassInfo125*, short);
void __dl__FPv(void*);
}

extern "C" FtClassInfo125* fn_125_E668(FtClassInfo125* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_125_data_72B0;
        info->vtable = lbl_125_data_72B0 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x2c, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
