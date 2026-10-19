#pragma force_active on
struct FtClassInfoObj {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_93_data_7FEC[];
void __ct__11ftClassInfoFb(FtClassInfoObj*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfoObj*, int, void*);
}

extern "C" FtClassInfoObj* fn_93_EA04(FtClassInfoObj* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_93_data_7FEC;
    info->vtable = lbl_93_data_7FEC + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 2, info);
    return info;
}
