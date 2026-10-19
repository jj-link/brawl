#pragma force_active on
struct FtClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_122_data_D660[];
void __ct__11ftClassInfoFb(FtClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfo*, int, void*);
}

extern "C" FtClassInfo* fn_122_13BDC(FtClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_122_data_D660;
    info->vtable = lbl_122_data_D660 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x2e, info);
    return info;
}
