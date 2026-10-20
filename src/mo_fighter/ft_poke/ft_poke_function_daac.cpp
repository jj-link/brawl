#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_116_data_6E50[];
extern ftClassInfoLike g_ftClassInfoNull;
void __dt__11ftClassInfoFv(ftClassInfoLike*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, ftClassInfoLike*);
}

extern "C" ftClassInfoLike* fn_116_DAAC(ftClassInfoLike* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_116_data_6E50;
        info->vtable = lbl_116_data_6E50 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x1d, &g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
