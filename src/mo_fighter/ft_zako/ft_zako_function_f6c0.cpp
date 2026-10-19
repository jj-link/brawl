#pragma force_active on
struct FtClassInfoDerived {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_126_data_7300[];
void __ct__11ftClassInfoFb(FtClassInfoDerived*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfoDerived*, int, void*);
}

extern "C" FtClassInfoDerived* fn_126_F6C0(FtClassInfoDerived* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_126_data_7300;
    info->vtable = lbl_126_data_7300 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x35, info);
    return info;
}
