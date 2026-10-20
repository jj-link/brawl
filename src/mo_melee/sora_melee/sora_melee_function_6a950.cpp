#include <types.h>
#include <ut/ut_list.h>
#pragma force_active on

struct SoNode {
    SoNode* next;
    u32 pad4;
    u32 pad8;
    struct SoData* data;
};

struct SoData {
    u8 pad[0x30];
    u32 flags;
};

extern "C" bool fn_27_6A950(u8* self, u32 flag) {
    utList* list = (utList*)(self + 0x14);
    SoNode* node = (SoNode*)list->getNode(0);
    u32 bit = 1U << flag;
    while (node != 0) {
        if ((node->data->flags >> 8) & bit) {
            return true;
        }
        node = node->next;
    }
    return false;
}
