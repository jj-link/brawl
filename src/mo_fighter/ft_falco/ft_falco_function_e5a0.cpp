#pragma force_active on
struct FtClassInfo108 {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_108_data_7234[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(FtClassInfo108*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfo108*, int, void*);
}

extern "C" FtClassInfo108* fn_108_E5A0(FtClassInfo108* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_108_data_7234;
        info->vtable = lbl_108_data_7234 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x13, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
