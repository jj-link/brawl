#pragma force_active on
struct FtClassInfoObj {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_104_data_7184[];
void __ct__11ftClassInfoFb(FtClassInfoObj*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfoObj*, int, void*);
}

extern "C" FtClassInfoObj* fn_104_DD00(FtClassInfoObj* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_104_data_7184;
    info->vtable = lbl_104_data_7184 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 13, info);
    return info;
}
