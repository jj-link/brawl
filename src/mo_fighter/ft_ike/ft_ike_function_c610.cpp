#pragma force_active on
struct ClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_119_data_5C60[];
void __ct__11ftClassInfoFb(ClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ClassInfo*, int, void*);
}

extern "C" ClassInfo* fn_119_C610(ClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_119_data_5C60;
    info->vtable = lbl_119_data_5C60 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x22, info);
    return info;
}
