#include <types.h>
#pragma force_active on

struct FnNode {
    FnNode* next;
    u32 pad4;
    u32 pad8;
    int id;
    u8 kind;
};

extern "C" {
FnNode* fn_27_232304(const void* self, int id, u32 kind) {
    FnNode* n = *(FnNode**)((char*)self + 0x40);
    while (n != 0) {
        if (n->id == id && n->kind == kind) {
            return n;
        }
        n = n->next;
    }
    return 0;
}
}
