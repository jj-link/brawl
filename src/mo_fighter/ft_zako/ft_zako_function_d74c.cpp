#pragma force_active on
struct ClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_126_data_684C[];
void __ct__11ftClassInfoFb(ClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ClassInfo*, int, void*);
}

extern "C" ClassInfo* fn_126_D74C(ClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_126_data_684C;
    info->vtable = lbl_126_data_684C + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x34, info);
    return info;
}
