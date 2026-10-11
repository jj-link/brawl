#include <ft/ft_entry.h>
#include <types.h>

struct PeachExtendParamAccesser {
    void* primaryVtable;
    u32 baseState;
    void* secondaryVtable;
    ftKind kind;
};

extern "C" {
PeachExtendParamAccesser* __ct__21ftExtendParamAccesserF6ftKind(PeachExtendParamAccesser* accesser, ftKind kind);
extern u8 lbl_103_data_50[];

PeachExtendParamAccesser* fn_103_CF9C(PeachExtendParamAccesser* accesser) {
    __ct__21ftExtendParamAccesserF6ftKind(accesser, Fighter_Peach);
    u8* table = lbl_103_data_50;
    accesser->secondaryVtable = table;
    accesser->primaryVtable = table + 8;
    return accesser;
}
}
