#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_116_data_9868[];
void __ct__11ftClassInfoFb(ftClassInfoLike*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, ftClassInfoLike*);
}

extern "C" ftClassInfoLike* fn_116_1A404(ftClassInfoLike* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_116_data_9868;
    info->vtable = lbl_116_data_9868 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x1e, info);
    return info;
}
