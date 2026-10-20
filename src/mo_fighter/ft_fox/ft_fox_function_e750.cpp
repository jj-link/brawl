#pragma force_active on
struct FoxClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_97_data_726C[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(FoxClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(FoxClassInfo*, int, void*);
}

extern "C" FoxClassInfo* fn_97_E750(FoxClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_97_data_726C;
        info->vtable = lbl_97_data_726C + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 6, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
