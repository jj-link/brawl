#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_109_data_6110[];
void __ct__11ftClassInfoFb(ftClassInfoLike*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
}

extern "C" ftClassInfoLike* fn_109_C060(ftClassInfoLike* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_109_data_6110;
    info->vtable = lbl_109_data_6110 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x14, info);
    return info;
}
