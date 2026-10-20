#include <st/module.h>
#pragma force_active on

struct ftClassInfo {
    const void* vtable;
    unsigned int baseState;
    const void* typeInfo;
};

extern "C" {
extern const unsigned char lbl_120_data_6F38[];
extern char g_ftClassInfoNull[];
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(void* self, int kind, void* info);
void* __dt__11ftClassInfoFv(void* self, short flag);
}

extern "C" ftClassInfo* fn_120_CD58(ftClassInfo* info, short deleting) {
    if (info) {
        info->typeInfo = lbl_120_data_6F38;
        info->vtable = lbl_120_data_6F38 + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, 0x23, g_ftClassInfoNull);
        __dt__11ftClassInfoFv(info, 0);
        if (deleting > 0) operator delete(info);
    }
    return info;
}
