#pragma force_active on
struct FtClassInfo108 {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_108_data_7234[];
void __ct__11ftClassInfoFb(FtClassInfo108*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfo108*, int, void*);
}

extern "C" FtClassInfo108* fn_108_E548(FtClassInfo108* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_108_data_7234;
    info->vtable = lbl_108_data_7234 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x13, info);
    return info;
}
