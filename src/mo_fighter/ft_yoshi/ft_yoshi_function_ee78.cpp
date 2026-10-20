#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_95_data_7AD4[];
extern char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(ftClassInfoLike*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
void __dl__FPv(void*);
}

extern "C" ftClassInfoLike* fn_95_EE78(ftClassInfoLike* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_95_data_7AD4;
        info->vtable = lbl_95_data_7AD4 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 4, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) __dl__FPv(info);
    }
    return info;
}
