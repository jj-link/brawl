#pragma force_active on
struct ftClassInfoObj {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_105_data_7EB8[];
void __ct__11ftClassInfoFb(ftClassInfoObj*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoObj*, int, void*);
}

extern "C" ftClassInfoObj* fn_105_12D24(ftClassInfoObj* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_105_data_7EB8;
    info->vtable = lbl_105_data_7EB8 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0xf, info);
    return info;
}
