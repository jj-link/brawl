#include <types.h>
#pragma force_active on

class ListNode {
public:
    u8 pad0[8];
    u8 cnt;
    u8 pad9[0xb];
    virtual void vf0();
    virtual void vf1(void* arg);
};

extern "C" void removeExist__6utListFP10utListNode(void* list, void* node);
extern "C" void addTail__6utListFP10utListNode(void* list, void* node);

extern "C" int fn_27_145080(u8* self, ListNode* node, void* arg) {
    s32 var_r0;
    u32 var_r0_2;
    s32 temp_r3;
    u8 temp_r6;

    temp_r6 = node->cnt;
    if (((s32)temp_r6 != 0) &&
        (temp_r3 = temp_r6 - 1, node->cnt = temp_r3,
         ((((u8)temp_r3) == 0) != 0))) {
        var_r0 = 1;
    } else {
        var_r0 = 0;
    }

    if (var_r0 != 0) {
        node->vf1(arg);
        var_r0_2 = 1U;
    } else {
        var_r0_2 = 0U;
    }

    if (var_r0_2 == 1U) {
        removeExist__6utListFP10utListNode(self + 0x1088, node);
        removeExist__6utListFP10utListNode(self + 0x1094, node);
        addTail__6utListFP10utListNode(self + 0x107c, node);
        return 1;
    }
    return 0;
}
