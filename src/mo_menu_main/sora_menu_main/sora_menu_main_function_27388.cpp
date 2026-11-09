#include <types.h>
#pragma force_active on

extern "C" void fn_2_2777C();
extern "C" void fn_2_27434(void* a, void* b);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int a, unsigned long b);
extern "C" int isCharUsable__6muMenuFiii(int a);

extern "C" void fn_2_27388(unsigned char* self, int a1, int a2, int a3) {
    *(int*)(self + 0x654) = a1;
    *(int*)(self + 0x670) = 0;
    *(int*)(self + 0x674) = a2;
    *(int*)(self + 0x66C) = a3;
    self[0x67C] = 0;
    self[0x67D] = 0;
    fn_2_2777C();
    *(void**)(self + 0x678) = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2a, 0x234);
    unsigned char count = 0;
    for (int i = 0; i < 0x23; i++) {
        if (isCharUsable__6muMenuFiii(i)) {
            ((int*)*(void**)(self + 0x678))[count] = i;
            count++;
        }
    }
    unsigned char* buf = *(unsigned char**)(self + 0x678);
    buf[0x8C] = count;
    fn_2_27434(self, buf);
}
