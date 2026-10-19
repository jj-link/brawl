#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_115_data_7490[];
void __ct__11ftClassInfoFb(ftClassInfoLike*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
}

extern "C" ftClassInfoLike* fn_115_D7D4(ftClassInfoLike* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_115_data_7490;
    info->vtable = lbl_115_data_7490 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x1b, info);
    return info;
}
