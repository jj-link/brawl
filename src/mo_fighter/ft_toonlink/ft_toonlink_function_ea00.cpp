#pragma force_active on
struct ToonLinkClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_121_data_810C[];
void __ct__11ftClassInfoFb(ToonLinkClassInfo*, bool);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(ToonLinkClassInfo*, int, void*);
}

extern "C" ToonLinkClassInfo* fn_121_EA00(ToonLinkClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    info->typeInfo = lbl_121_data_810C;
    info->vtable = lbl_121_data_810C + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x29, info);
    return info;
}
