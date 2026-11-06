#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef int s32;

typedef struct Owner {
    u8 pad[0x72];
    u8 state;
} Owner;

extern void fn_802319E4(u32, const char *);
extern void fn_80231A14(u32, const char *, s32, u16);
extern void fn_80251878(u8 *);
extern u8 *fn_80251AD0(Owner *, s32);
extern u8 *fn_80251B24(s32);
extern void fn_8025474C(Owner *, s32, u16, s32, u8);
extern void fn_80254BF4(Owner *, s32, s32);
extern void fn_802564E4(Owner *);
extern void *memcpy(void *, const void *, u32);
extern u8 lbl_8052D5A8[];
extern char lbl_80483F18[];
extern char lbl_80483F38[];

void fn_80250678(Owner *arg0, u16 arg1, u16 arg2, u32 arg3, s16 arg4)
{
    u8 *p;
    Owner *self;
    s32 r0;
    s32 r6;
    u8 r7;
    u16 n;
    u16 t;

    self = arg0;
    p = fn_80251AD0(self, arg1);
    if (lbl_8052D5A8[0x414] >= 4) {
        fn_80231A14(0x90003, lbl_80483F18, arg1, arg2);
    }
    if (p == 0) {
        p = fn_80251B24(arg1);
        if (p == 0) {
            fn_80254BF4(self, arg1, 0);
            fn_802564E4(self);
            if (lbl_8052D5A8[0x414] >= 4) {
                fn_802319E4(0x90003, lbl_80483F38);
            }
            return;
        }
        *((u8 *)self + arg1 + 0x24) = *p;
    }
    memcpy(p + 6, (u8 *)self + 0x62, 6);
    fn_80251878(p);
    *(Owner **)(p + 0x6C) = self;
    n = *(u16 *)(p + 0x12);
    if (n < arg2) {
        arg2 = n;
    }
    *(u16 *)(p + 0x12) = arg2;
    *(u16 *)(p + 0x14) = arg2;
    if (self->state == 0) {
        if (arg3 == 0) {
            self->state = 1;
        } else {
            self->state = 2;
        }
    }
    if (arg3 == 0) {
        r6 = 0;
        r7 = 0;
    } else if (self->state == 2) {
        *(s16 *)(p + 0x98) = arg4;
        if (arg4 == 0) {
            p[0x24] = 1;
        }
        t = *(u16 *)(p + 0x9C);
        r6 = 0xE0;
        r0 = 7;
        if (t < 7) {
            r0 = t;
        }
        r7 = (u8)r0;
        *(s16 *)(p + 0x9A) = r7;
    } else {
        r6 = 0;
        r7 = 0;
    }
    fn_8025474C(self, arg1, *(u16 *)(p + 0x12), r6, r7);
}
