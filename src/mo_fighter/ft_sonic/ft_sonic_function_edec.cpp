#pragma force_active on
struct ftClassInfoStub {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_123_data_6460[];
void __ct__11ftClassInfoFb(ftClassInfoStub*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoStub*, int, void*);
}

extern "C" ftClassInfoStub* fn_123_EDEC(ftClassInfoStub* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_123_data_6460;
    info->vtable = lbl_123_data_6460 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x2f, info);
    return info;
}
