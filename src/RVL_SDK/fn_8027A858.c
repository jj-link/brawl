#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;

extern u64 OSGetTime(void);
extern int fn_8021AE80(int);
extern void fn_8027B410(int, int, int, signed char);
extern f32 lbl_805A3B88;

struct _8027A858 {
    u32 unk00;
    f32 unk04;
    u8 pad08[0x1C];
    u32 unk24;
    u8 pad28[8];
    u32 unk30;
    u32 unk34;
    u8 pad38[9];
    u8 unk41;
    u8 unk42;
    u8 unk43;
};

void fn_8027A858(struct _8027A858 *self) {
    if (self->unk41 == 0) {
        f32 f = self->unk04;
        f32 prod = lbl_805A3B88 * f;
        int x;
        fn_8027B410(self->unk24, self->unk00, x, (signed char)prod);
        if (fn_8021AE80(self->unk00) != 0) {
            if (self->unk42 == 0) {
                u64 t = OSGetTime();
                self->unk34 = (u32)t;
                self->unk30 = (u32)(t >> 32);
            }
            self->unk42 = 1;
            self->unk43 = 0;
        }
    }
}
