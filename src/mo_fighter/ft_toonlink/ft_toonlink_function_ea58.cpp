#pragma force_active on
struct ToonLinkClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_121_data_810C[];
extern unsigned char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ToonLinkClassInfo*, int, void*);
void __dt__11ftClassInfoFv(ToonLinkClassInfo*, short);
}

extern "C" ToonLinkClassInfo* fn_121_EA58(ToonLinkClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_121_data_810C;
        info->vtable = lbl_121_data_810C + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x29, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
