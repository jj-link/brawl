#include <types.h>
#pragma force_active on
extern "C" void* memcpy(void*, const void*, unsigned long);
struct Entry { f32 a, b; u32 c, d; u8 e; };
struct Table { Entry e[11]; };
extern "C" void* fn_6_0(void* self, u32 x, u32 y) {
    Table a = {{
        {0,9,0,x,17}, {9,9,0,x,17}, {10,15,0,x,17},
        {16,19,0,x,17}, {20,24,0,x,17}, {25,29,0,x,17},
        {30,30,0,x,17}, {31,31,0,x,17}, {31,31,0,x,17},
        {31,31,0,x,17}, {31,31,0,x,17}
    }};
    Table b = {{
        {0,9,0,y,1}, {9,9,0,y,1}, {10,15,0,y,1},
        {16,19,0,y,1}, {20,24,0,y,1}, {25,29,0,y,1},
        {30,30,0,y,1}, {31,31,0,y,1}, {32,32,0,y,1},
        {33,33,0,y,1}, {34,34,0,y,1}
    }};
    u8 f[11] = {0,1,2,3,4,5,6,7,8,9,10};
    memcpy(self, &a, 0xDC);
    memcpy((u8*)self + 0xDC, &b, 0xDC);
    memcpy((u8*)self + 0x1B8, f, 0xB);
    return self;
}