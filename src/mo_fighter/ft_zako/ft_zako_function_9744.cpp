#pragma force_active on
struct FtClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_126_data_52E8[];
void __ct__11ftClassInfoFb(FtClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfo*, int, void*);
}

extern "C" FtClassInfo* fn_126_9744(FtClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_126_data_52E8;
    info->vtable = lbl_126_data_52E8 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x32, info);
    return info;
}
