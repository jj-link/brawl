#pragma force_active on
struct FtClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_97_data_726C[];
void __ct__11ftClassInfoFb(FtClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfo*, int, void*);
}

extern "C" FtClassInfo* fn_97_E6F8(FtClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_97_data_726C;
    info->vtable = lbl_97_data_726C + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 6, info);
    return info;
}
