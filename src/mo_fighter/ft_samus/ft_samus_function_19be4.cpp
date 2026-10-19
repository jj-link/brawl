#pragma force_active on
struct ftClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_94_data_C57C[];
void __ct__11ftClassInfoFb(ftClassInfoLike*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoLike*, int, void*);
}

extern "C" ftClassInfoLike* fn_94_19BE4(ftClassInfoLike* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_94_data_C57C;
    info->vtable = lbl_94_data_C57C + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x18, info);
    return info;
}
