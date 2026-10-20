#pragma force_active on
struct PikminClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_113_data_6AAC[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(PikminClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(PikminClassInfo*, int, void*);
}

extern "C" PikminClassInfo* fn_113_FE94(PikminClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_113_data_6AAC;
        info->vtable = lbl_113_data_6AAC + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x19, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
