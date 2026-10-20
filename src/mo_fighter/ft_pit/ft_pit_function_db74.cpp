#pragma force_active on
struct PitClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern unsigned char lbl_112_data_68E0[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(PitClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(PitClassInfo*, int, void*);
void __dl__FPv(void*);
}

extern "C" PitClassInfo* fn_112_DB74(PitClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_112_data_68E0;
        info->vtable = lbl_112_data_68E0 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x17, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
