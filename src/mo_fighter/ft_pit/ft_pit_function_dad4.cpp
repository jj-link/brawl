#include <ft/ft_entry.h>
#include <types.h>
#pragma force_active on

struct ExtendParamAccesserLayout {
    void* primaryVtable;
    u32 baseState;
    void* secondaryVtable;
    ftKind kind;
};

extern "C" {
ExtendParamAccesserLayout* __ct__21ftExtendParamAccesserF6ftKind(ExtendParamAccesserLayout* accesser, ftKind kind);
extern u8 lbl_112_data_28[];

ExtendParamAccesserLayout* fn_112_DAD4(ExtendParamAccesserLayout* accesser) {
    __ct__21ftExtendParamAccesserF6ftKind(accesser, (ftKind)0x17);
    u8* table = lbl_112_data_28;
    accesser->secondaryVtable = table;
    accesser->primaryVtable = table + 8;
    return accesser;
}
}
