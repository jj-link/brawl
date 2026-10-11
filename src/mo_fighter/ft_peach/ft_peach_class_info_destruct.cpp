#include <ft/ft_class_info.h>
#include <sr/sr_common.h>
#include <types.h>

struct PeachClassInfo {
    void* primaryVtable;
    u32 baseState;
    void* secondaryVtable;
};

extern "C" {
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(PeachClassInfo* info, ftKind kind, PeachClassInfo* registeredInfo);
PeachClassInfo* __dt__11ftClassInfoFv(PeachClassInfo* info, s16 deleteFlag);
extern u8 lbl_103_data_6264[];

PeachClassInfo* fn_103_D03C(PeachClassInfo* info, s32 deleteFlag) {
    if (info != nullptr) {
        u8* table = lbl_103_data_6264;
        info->secondaryVtable = table;
        info->primaryVtable = table + 8;
        setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(
            info, Fighter_Peach, reinterpret_cast<PeachClassInfo*>(&g_ftClassInfoNull));
        s16 baseDeleteFlag = 0;
        __dt__11ftClassInfoFv(info, baseDeleteFlag);
        if (static_cast<s16>(deleteFlag) > 0) {
            ::operator delete(info);
        }
    }
    return info;
}
}
