#pragma force_active on
struct FtInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_104_data_C26C[];
void __ct__11ftClassInfoFb(FtInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtInfo*, int, void*);
}

extern "C" FtInfo* fn_104_1D848(FtInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_104_data_C26C;
    info->vtable = lbl_104_data_C26C + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0xe, info);
    return info;
}
