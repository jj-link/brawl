#pragma force_active on
struct Ft107ClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_107_data_8CF0[];
void __ct__11ftClassInfoFb(Ft107ClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(Ft107ClassInfo*, int, void*);
}

extern "C" Ft107ClassInfo* fn_107_FE48(Ft107ClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_107_data_8CF0;
    info->vtable = lbl_107_data_8CF0 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x12, info);
    return info;
}
