#include <types.h>
#pragma force_active on
typedef struct Entry {
    u8 state;
    u8 flags;
    u8 pad0[2];
    u16 type;
    u16 id;
    u8 pad1[0xA];
    u16 field12;
    u8 pad2[0xC];
    void (*callback)(u16, u32);
    u8 pad3[0x3C];
} Entry;
typedef struct Req {
    u16 a0;
    u8 b2;
    u8 pad0;
    u16 a4;
    u8 pad1[0x1A];
    u8 b20;
} Req;
extern u8 lbl_8052C4C0[];
extern void fn_8024A9AC(u32, void *);
static Entry *find(u32 id)
{
    u16 xx;
    Entry *p;
    for (xx = 0, p = (Entry *)(lbl_8052C4C0 + 0xAC); xx < 8; xx++, p++) {
        if (p->state != 0 && p->id == id) {
            return p;
        }
    }
    return 0;
}
void fn_80243B3C(u32 arg0, Req *arg1)
{
    Entry *p = find(arg0);
    if (p != 0) {
        if (arg1->b2 == 0 || arg1->a4 > 0x69B) {
            p->field12 = 0x69B;
        } else {
            p->field12 = arg1->a4;
        }
        arg1->b20 = 0;
        arg1->b2 = 0;
        arg1->a0 = 0;
        fn_8024A9AC(arg0, arg1);
        p->flags = p->flags | 2;
        if (p->flags & 4) {
            p->state = 4;
            p->callback(p->type, 0x100);
        }
    }
}