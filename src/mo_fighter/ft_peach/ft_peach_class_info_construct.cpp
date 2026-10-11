#include <ft/ft_entry.h>
#include <types.h>

struct PeachClassInfo {
    void* primaryVtable;
    u32 baseState;
    void* secondaryVtable;
};

extern "C" {
PeachClassInfo* __ct__11ftClassInfoFb(PeachClassInfo* info, bool isNull);
void setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(PeachClassInfo* info, ftKind kind, PeachClassInfo* registeredInfo);
extern u8 lbl_103_data_6264[];

PeachClassInfo* fn_103_CFE4(PeachClassInfo* info) {
    __ct__11ftClassInfoFb(info, false);
    u8* table = lbl_103_data_6264;
    info->secondaryVtable = table;
    info->primaryVtable = table + 8;
    setClassInfo__11ftClassInfoF6ftKindP11ftClassInfo(info, Fighter_Peach, info);
    return info;
}
}
