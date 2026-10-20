#pragma force_active on
struct IceClimberClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_105_data_7EB8[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(IceClimberClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(IceClimberClassInfo*, int, void*);
}

extern "C" IceClimberClassInfo* fn_105_12D7C(IceClimberClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_105_data_7EB8;
        info->vtable = lbl_105_data_7EB8 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0xf, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
