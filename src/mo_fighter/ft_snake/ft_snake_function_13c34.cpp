#pragma force_active on
struct SnakeClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_122_data_D660[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(SnakeClassInfo*, int, void*);
void __dt__11ftClassInfoFv(SnakeClassInfo*, short);
void __dl__FPv(void*);
}

extern "C" SnakeClassInfo* fn_122_13C34(SnakeClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_122_data_D660;
        info->vtable = lbl_122_data_D660 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x2e, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
