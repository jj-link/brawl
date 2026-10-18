#include <types.h>
#include <ut/ut_list.h>
#pragma force_active on

struct fnListNode {
    fnListNode* next;
    u32 pad[2];
    struct {
        u8 pad[0x30];
        u32 bits;
    }* data;
};

extern "C" s32 fn_27_6A770(u8* self, s32 id) {
    if (id != -1) {
        utList* list = (utList*)(self + 0x14);
        for (fnListNode* node = (fnListNode*)list->getNode(0); node != 0; node = node->next) {
            u32 field = (node->data->bits >> 1) & 0x7f;
            if (id == (s32)field) {
                return 1;
            }
        }
        return 0;
    }

    s32 v = *(s32*)(self + 0x1c);
    return (u32)(-v | v) >> 31;
}
