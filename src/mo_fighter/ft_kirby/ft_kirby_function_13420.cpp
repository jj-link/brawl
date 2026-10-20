#pragma force_active on
struct ClassInfoObj {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_96_data_AFB0[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ClassInfoObj*, int, void*);
void __dt__11ftClassInfoFv(ClassInfoObj*, short);
}

extern "C" ClassInfoObj* fn_96_13420(ClassInfoObj* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_96_data_AFB0;
        info->vtable = lbl_96_data_AFB0 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 5, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
