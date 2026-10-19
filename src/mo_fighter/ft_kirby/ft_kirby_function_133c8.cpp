#pragma force_active on
struct ClassInfoObj {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_96_data_AFB0[];
void __ct__11ftClassInfoFb(ClassInfoObj*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ClassInfoObj*, int, void*);
}

extern "C" ClassInfoObj* fn_96_133C8(ClassInfoObj* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_96_data_AFB0;
    info->vtable = lbl_96_data_AFB0 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 5, info);
    return info;
}
