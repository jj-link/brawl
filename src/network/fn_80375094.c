#include <types.h>
#pragma force_active on

typedef struct Cfg {
    u8 pad0[0x20];
    s32 unk20;
    u8 pad24[0x1C];
    s32 unk40;
} Cfg;

typedef struct State {
    s32 unk0;
    u16 unk4;
    u8 pad6[2];
    Cfg *unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 pad18[0x74];
    s32 unk8C;
} State;

extern void fn_80374778(State *self);
extern int fn_80373AA0(State *self, int a1, int a2, int a3);
extern int fn_80373C54(State *self, int a1);
extern int fn_803736BC(int a1, void *a2);
extern s32 fn_803783C4(Cfg *cfg, s32 a1, u16 a2, u8 *buf, s32 a5);
extern u32 fn_8035D728(void);
extern s32 fn_803739B8(Cfg *a0, State *a1, s32 a2, u16 a3, s32 a4, s32 a5, s32 a6);
extern void *memcpy(void *dst, const void *src, u32 len);
extern s16 lbl_8059F980;

int fn_80375094(State *self, int arg1, int arg2) {
    int flag;
    s32 off;
    u16 cnt;
    s32 tmp;
    s32 r;
    Cfg *cfg;
    s16 sp8;
    u8 buf[0xC];

    if (self->unkC != 3) {
        if (self->unkC < 5) {
            if (self->unk10 != 0) {
                fn_80374778(self);
                if (fn_80373AA0(self, 7, 0, 0) == 0) {
                    flag = 0;
                    goto end1;
                }
            } else {
                if (self->unkC == 4) {
                    self->unk14 = 1;
                }
                fn_80374778(self);
            }
        } else if (self->unkC != 7) {
            fn_80374778(self);
            if (fn_80373C54(self, 2) == 0) {
                flag = 0;
                goto end1;
            }
        }
        flag = 1;
    end1:
        return (flag != 0);
    }

    if (arg2 < 0x20) {
        if (self->unkC < 5) {
            if (self->unk10 != 0) {
                fn_80374778(self);
                if (fn_80373AA0(self, 7, 0, 0) == 0) {
                    flag = 0;
                    goto end2;
                }
            } else {
                if (self->unkC == 4) {
                    self->unk14 = 1;
                }
                fn_80374778(self);
            }
        } else if (self->unkC != 7) {
            fn_80374778(self);
            if (fn_80373C54(self, 2) == 0) {
                flag = 0;
                goto end2;
            }
        }
        flag = 1;
    end2:
        return (flag != 0);
    }

    if (fn_803736BC(arg1, (char *)self + 0x68) == 0) {
        if (self->unkC < 5) {
            if (self->unk10 != 0) {
                fn_80374778(self);
                if (fn_80373AA0(self, 7, 0, 0) == 0) {
                    flag = 0;
                    goto end3;
                }
            } else {
                if (self->unkC == 4) {
                    self->unk14 = 1;
                }
                fn_80374778(self);
            }
        } else if (self->unkC != 7) {
            fn_80374778(self);
            if (fn_80373C54(self, 2) == 0) {
                flag = 0;
                goto end3;
            }
        }
        flag = 1;
    end3:
        return (flag != 0);
    }

    cfg = self->unk8;
    if (cfg->unk20 == 0) {
        off = 0;
        cnt = self->unk4;
        tmp = self->unk0;
        if (cfg->unk40 == 2) {
            sp8 = 3;
            memcpy(buf, &sp8, 2);
            off = 2;
        }
        memcpy(buf + off, &lbl_8059F980, 2);
        off += 2;
        buf[off++] = 0x68;
        r = fn_803783C4(cfg, tmp, cnt, buf, off);
        if (((u32)(-r | r) >> 31) == 0) {
            return 0;
        }
        fn_80374778(self);
        return 1;
    }

    self->unkC = 4;
    return fn_803739B8(self->unk8, self, self->unk0, self->unk4, fn_8035D728() - self->unk8C, arg1 + 0x20, arg2 - 0x20) != 0;
}
