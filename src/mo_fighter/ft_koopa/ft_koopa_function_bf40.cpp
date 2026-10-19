#pragma force_active on
struct ClassInfoLike {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_102_data_5DD8[];
void __ct__11ftClassInfoFb(ClassInfoLike*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ClassInfoLike*, int, void*);
}

extern "C" ClassInfoLike* fn_102_BF40(ClassInfoLike* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_102_data_5DD8;
    info->vtable = lbl_102_data_5DD8 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 11, info);
    return info;
}
