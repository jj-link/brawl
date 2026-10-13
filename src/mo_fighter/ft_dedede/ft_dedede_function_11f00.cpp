class BaseItem;
#include <so/item/so_item_pick_transactor_impl.h>

struct DededeSearchDecision {
    int reserved;
    int status;
};

// This callback updates only the packed flag byte, not the trailing padding.
struct DededeItemInfoFlags {
    bool visible : 1;
    bool holdAnim : 1;
    unsigned char attachGroup : 6;
};

extern "C" {
extern const char lbl_117_data_8A04[], lbl_117_data_8A58[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
bool fn_117_11BC0(void*, DededeSearchDecision*, soModuleAccesser*);
bool fn_27_BE760(void*, void*, soItemInfo*, soModuleAccesser*);

bool fn_117_11F00(void* self, void* search, soItemInfo* info, soModuleAccesser* accesser) {
    DededeSearchDecision decision;
    void* dededeSearch = __dynamic_cast(search, 8, lbl_117_data_8A04, lbl_117_data_8A58, 1);
    if (fn_117_11BC0(dededeSearch, &decision, accesser)) {
        info->m_item = 0;
        info->m_kind = static_cast<itKind>(-1);
        info->m_trait.m_mask = 0;
        info->m_size = itParam::Size_Small;
        DededeItemInfoFlags* flags = reinterpret_cast<DededeItemInfoFlags*>(
            reinterpret_cast<unsigned char*>(info) + 0x10);
        flags->visible = true;
        flags->holdAnim = false;
        flags->attachGroup = itParam::Attach_Group_None;
        return true;
    }
    return fn_27_BE760(self, search, info, accesser);
}
}
