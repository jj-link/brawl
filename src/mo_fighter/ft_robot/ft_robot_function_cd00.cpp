#pragma force_active on
struct ftClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_120_data_6F38[];
void __ct__11ftClassInfoFb(ftClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfo*, int, ftClassInfo*);
}

extern "C" ftClassInfo* fn_120_CD00(ftClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_120_data_6F38;
    info->vtable = lbl_120_data_6F38 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x23, info);
    return info;
}
