#pragma force_active on
struct FtClassInfoObj {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_104_data_7184[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FtClassInfoObj*, int, void*);
void __dt__11ftClassInfoFv(FtClassInfoObj*, short);
void __dl__FPv(void*);
}

extern "C" FtClassInfoObj* fn_104_DD58(FtClassInfoObj* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_104_data_7184;
        info->vtable = lbl_104_data_7184 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 13, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
