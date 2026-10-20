#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_94_data_C57C[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
void __dt__11ftClassInfoFv(ftClassInfoLike*, short);
void __dl__FPv(void*);
}

extern "C" ftClassInfoLike* fn_94_19C3C(ftClassInfoLike* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_94_data_C57C;
        info->vtable = lbl_94_data_C57C + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x18, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
