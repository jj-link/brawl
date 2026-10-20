#pragma force_active on
extern "C" {
extern const unsigned char lbl_102_data_5DD8[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(void*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void*, int, void*);
void __dl__FPv(void*);
}

struct KoopaClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" KoopaClassInfo* fn_102_BF98(KoopaClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_102_data_5DD8;
        info->vtable = lbl_102_data_5DD8 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 11, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
