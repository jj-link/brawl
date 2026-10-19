#pragma force_active on
struct FtInfo113 {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_113_data_6AAC[];
void __ct__11ftClassInfoFb(FtInfo113*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtInfo113*, int, FtInfo113*);
}

extern "C" FtInfo113* fn_113_FE3C(FtInfo113* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_113_data_6AAC;
    info->vtable = lbl_113_data_6AAC + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x19, info);
    return info;
}
