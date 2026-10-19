#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_95_data_7AD4[];
void __ct__11ftClassInfoFb(ftClassInfoLike*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
}

extern "C" ftClassInfoLike* fn_95_EE20(ftClassInfoLike* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_95_data_7AD4;
    info->vtable = lbl_95_data_7AD4 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 4, info);
    return info;
}
