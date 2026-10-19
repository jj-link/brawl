#pragma force_active on
struct FtClassInfoObj {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_112_data_68E0[];
void __ct__11ftClassInfoFb(FtClassInfoObj*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfoObj*, int, void*);
}

extern "C" FtClassInfoObj* fn_112_DB1C(FtClassInfoObj* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_112_data_68E0;
    info->vtable = lbl_112_data_68E0 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x17, info);
    return info;
}
