#include <types.h>
#pragma force_active on
extern "C" void* fn_8015C1B0(void*, void*);
struct ListHolder { char pad[0x24]; void* head; };
extern "C" s32 fn_80164510(ListHolder* self, void (*func)(void*, s32), s32 arg, s32 flag, void* target) {
    s32 count = 0;
    void* node = fn_8015C1B0(&self->head, NULL);
    while (node) {
        void* next = fn_8015C1B0(&self->head, node);
        if (flag != 0 || *(s32*)((char*)node + 0xC) == 1) {
            void* p = node;
            int found = 0;
            while (!found && (p = *(void**)((char*)p + 0xF4)) != NULL) {
                if (p == target) found = 1;
            }
            if (found) {
                func(node, arg);
                count++;
            }
        }
        node = next;
    }
    return count;
}