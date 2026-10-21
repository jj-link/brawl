#include <types.h>
#pragma force_active on

struct FnNode {
    s32 field0;
    u32 pad4;
    u32 pad8;
    s32 field_c;
    u32 pad_10[12];
    struct FnNode* next;
};

void* fn_8036FD58(void* self, s32 arg1) {
    void* obj = *(void**)self;
    struct FnNode* node = *(struct FnNode**)((char*)obj + 0x450);
    while (node != 0) {
        if (node->field_c == arg1 && node->field0 == 0x69) {
            return node;
        }
        node = node->next;
    }
    return 0;
}
