#pragma force_active on
struct LinkClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_93_data_7FEC[];
extern unsigned char g_ftClassInfoNull[];
void __dt__11ftClassInfoFv(LinkClassInfo*, short);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(LinkClassInfo*, int, void*);
}

extern "C" LinkClassInfo* fn_93_EA5C(LinkClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_93_data_7FEC;
        info->vtable = lbl_93_data_7FEC + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 2, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
