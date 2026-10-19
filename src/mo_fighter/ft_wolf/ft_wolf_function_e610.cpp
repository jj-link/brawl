#pragma force_active on
struct FtClassInfo125 {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_125_data_72B0[];
void __ct__11ftClassInfoFb(FtClassInfo125*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfo125*, int, void*);
}

extern "C" FtClassInfo125* fn_125_E610(FtClassInfo125* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_125_data_72B0;
    info->vtable = lbl_125_data_72B0 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x2c, info);
    return info;
}
