#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);

struct ListHolder {
    char pad[0x24];
    void* head;
};

extern "C" s32 fn_801643E0(ListHolder* self, void (*func)(void*, s32), s32 a2, s32 flag) {
    s32 count = 0;
    void* node = fn_8015C1B0(&self->head, NULL);
    while (node) {
        void* next = fn_8015C1B0(&self->head, node);
        if (flag != 0 || (*(s32*)((char*)node + 0xC)) == 1) {
            func(node, a2);
            count++;
        }
        node = next;
    }
    return count;
}
