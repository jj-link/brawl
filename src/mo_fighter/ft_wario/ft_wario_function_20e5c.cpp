#pragma force_active on
struct LuigiClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_110_data_A050[];
void __ct__11ftClassInfoFb(LuigiClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(LuigiClassInfo*, int, void*);
}

extern "C" LuigiClassInfo* fn_110_20E5C(LuigiClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_110_data_A050;
    info->vtable = lbl_110_data_A050 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x31, info);
    return info;
}
