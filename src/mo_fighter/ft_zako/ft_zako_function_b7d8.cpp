#pragma force_active on
struct ftClassInfoBase {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_126_data_5D98[];
void __ct__11ftClassInfoFb(ftClassInfoBase*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ftClassInfoBase*, int, void*);
}

extern "C" ftClassInfoBase* fn_126_B7D8(ftClassInfoBase* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_126_data_5D98;
    info->vtable = lbl_126_data_5D98 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x33, info);
    return info;
}
