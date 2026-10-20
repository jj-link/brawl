#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_116_data_9868[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
void __dt__11ftClassInfoFv(ftClassInfoLike*, short);
void __dl__FPv(void*);
}

extern "C" ftClassInfoLike* fn_116_1A45C(ftClassInfoLike* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_116_data_9868;
        info->vtable = lbl_116_data_9868 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x1e, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
