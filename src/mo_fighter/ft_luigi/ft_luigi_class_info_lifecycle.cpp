struct LuigiClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_99_data_6290[];
extern unsigned char g_ftClassInfoNull[];
void __ct__11ftClassInfoFb(LuigiClassInfo*, bool);
void __dt__11ftClassInfoFv(LuigiClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(LuigiClassInfo*, int, void*);
}

extern "C" LuigiClassInfo* fn_99_B92C(LuigiClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_99_data_6290;
    info->vtable = lbl_99_data_6290 + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 8, info);
    return info;
}

extern "C" LuigiClassInfo* fn_99_B984(LuigiClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_99_data_6290;
        info->vtable = lbl_99_data_6290 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 8, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
