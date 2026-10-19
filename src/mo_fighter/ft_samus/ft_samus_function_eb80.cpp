#pragma force_active on
struct FtClassInfoSelf {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_94_data_9850[];
void __ct__11ftClassInfoFb(FtClassInfoSelf*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfoSelf*, int, void*);
}

extern "C" FtClassInfoSelf* fn_94_EB80(FtClassInfoSelf* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_94_data_9850;
    info->vtable = lbl_94_data_9850 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 3, info);
    return info;
}
