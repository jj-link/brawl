#pragma force_active on
struct LuigiClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_110_data_60E4[];
void __ct__11ftClassInfoFb(LuigiClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(LuigiClassInfo*, int, void*);
}

extern "C" LuigiClassInfo* fn_110_C7A8(LuigiClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_110_data_60E4;
    info->vtable = lbl_110_data_60E4 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x15, info);
    return info;
}
