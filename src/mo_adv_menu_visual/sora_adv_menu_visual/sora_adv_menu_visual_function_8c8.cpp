#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B6E08(void* a, float* b);
extern const float lbl_29_rodata_28;

void fn_29_8C8(char* self, float val) {
    float local[3];
    local[0] = val;
    local[1] = val;
    local[2] = lbl_29_rodata_28;
    
    char* p1, *p2, *p3;
    int c1, c2, c3;
    
    p1 = self + 0x60;
    c1 = 0x18;
    do {
        fn_800B6E08(*(void**)(p1 + 0x4C), &local[0]);
        c1++;
        p1 += 4;
    } while (c1 < 0x1A);
    
    fn_800B6E08(*(void**)(self + 0x54), &local[0]);
    fn_800B6E08(*(void**)(self + 0x58), &local[0]);
    
    p2 = self + 0x10;
    c2 = 4;
    do {
        fn_800B6E08(*(void**)(p2 + 0x4C), &local[0]);
        c2++;
        p2 += 4;
    } while (c2 < 0xE);
    
    p3 = self + 0x38;
    c3 = 0xE;
    do {
        fn_800B6E08(*(void**)(p3 + 0x4C), &local[0]);
        c3++;
        p3 += 4;
    } while (c3 < 0x18);
}
}