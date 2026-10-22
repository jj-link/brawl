#include <types.h>
#pragma force_active on

extern "C" u32 fn_800130A8(void* a, void* b);
extern "C" void Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(char* list, void** it, void* node);

extern "C" void fn_80012470(char* self, char* node) {
    char* key = node + 0x2c;
    char* cur = self + 0x40;
    void* it;
    while (1) {
        if (((*(u8*)(cur + 0x11)) >> 7) & 1) {
            break;
        }
        u32 idx = fn_800130A8(cur, key);
        if (idx == 0xFF) {
            break;
        }
        char* next = *(char**)(cur + idx * 4 + 0x18);
        if (next == 0) {
            break;
        }
        cur = next;
    }
    it = cur + 0x2c;
    Insert__Q44nw4r2ut6detail12LinkListImplFQ54nw4r2ut6detail12LinkListImpl8IteratorPQ34nw4r2ut12LinkListNode(cur + 0x28, &it, node);
}
