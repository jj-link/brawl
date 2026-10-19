#pragma force_active on
struct PurinClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_124_data_5AB8[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(PurinClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(PurinClassInfo*, int, void*);
void __dl__FPv(void*);
}

extern "C" PurinClassInfo* fn_124_B220(PurinClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_124_data_5AB8;
        info->vtable = lbl_124_data_5AB8 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x25, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) __dl__FPv(info);
    }
    return info;
}
