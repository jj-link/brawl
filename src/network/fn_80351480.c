#include <types.h>
#pragma force_active on
extern void fn_80350908(u32 *, u32);
extern u32 fn_80350A78(u32 *, u8 *, u32);
static inline u32 swap(u32 v) {
    u32 t = ((v >> 8) & 0x00FF00FF) | ((v << 8) & 0xFF00FF00);
    return (t << 16) | (t >> 16);
}
typedef struct { u32 a, b, c; } Three;
void fn_80351480(u32 *arg0, Three *__restrict src, u32 arg2) {
    u32 data[16], table[256];
    int i;
    arg0[4] = src->a;
    arg0[5] = src->b;
    arg0[6] = src->c;
    arg0[7] = arg2;
    fn_80350908(table, 0xEDB88320);
    for (i = 0; i < 16; i++) {
        data[i] = swap(arg0[i]);
    }
    arg0[15] = fn_80350A78(table, (u8 *)data, 0x3C);
    arg0[8] |= 1;
}
