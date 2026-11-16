#include <types.h>
#include <internal/mem.h>
#pragma force_active on

typedef struct {
    u16 a;
    u16 b;
    u8 c[4];
    u8 d;
    u8 e[0xFA - 9];
} Blk;

typedef struct {
    u16 pad;
    Blk blk;
} Buffer;

extern u16 fn_80257250(void *, u32 *);
extern u16 fn_80256EF0(void *, u32 *);
extern void fn_80257F60(u32, int, u32, u16 *);
extern void fn_80257BC8(u32, u16, u8, u32, u8 *);

s32 fn_80243624(void) {
    Buffer buf;
    u8 data[2];
    u16 sp8;
    u32 sp10;
    Blk *p;

    sp10 = 0;
    sp8 = 0x1002;
    if (fn_80257250(&buf, &sp10) != 0) {
        p = &buf.blk;
        memset(p, 0, 0xFA);
        p->a = 0xF;
        p->b = 1;
        p->d = 1;
        if (fn_80256EF0(p, &sp10) != 0) {
            sp10 = 0;
            return 0;
        }
    }
    fn_80257F60(sp10, 5, 1, &sp8);
    data[0] = 0;
    data[1] = 1;
    fn_80257BC8(sp10, 0x8001, 1, 2, data);
    return 1;
}