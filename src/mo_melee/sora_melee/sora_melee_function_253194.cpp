#pragma force_active on

typedef unsigned char u8;
typedef int s32;
typedef long long s64;

struct Info {
    u8 pad0[0x14];
    u8 kind;
    u8 pad15[0x40 - 0x15];
    s32 w40;
    s32 w44;
    u8 pad48[0x98 - 0x48];
    u8 b98;
    u8 pad99[0x9E - 0x99];
    u8 b9e;
    u8 pad9f[0xF4 - 0x9F];
    u8 bf4;
    u8 padf5[0xFA - 0xF5];
    u8 bfa;
};

struct Obj {
    u8 pad0[0x44];
    Info* info;
    u8 pad48[0xD3 - 0x48];
    u8 bd3;
    u8 padd4[0xF8 - 0xD4];
    s32 wf8;
    u8 padfc[0x100 - 0xFC];
    s32 w100;
    u8 pad104[0x1B4 - 0x104];
    s32 w1b4;
    s32 w1b8;
    u8 pad1bc[0x25C - 0x1BC];
    s32 w25c;
    s32 w260;
    s32 w264;
    u8 arr268[0x2C];
    u8 pad294[0x2A8 - 0x294];
    s32 w2a8;
    s32 w2ac;
    s32 w2b0;
    s32 w2b4;
};

extern "C" void fn_27_2498DC(Obj* p);
extern "C" void fn_27_254360(Obj* p, int v);
extern "C" int fn_8005227C(int a, int b, int bit);
extern "C" int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int kind);
extern "C" int getNumCharColor__6muMenuFiii(int kind);
extern "C" s32 lbl_27_data_52980[];

extern "C" void fn_27_253194(Obj* self) {
    fn_27_2498DC(self);
    Info* info = self->info;
    self->w2a8 = info->b98;
    self->w2b0 = info->b9e;
    if (self->w1b8 == 1) {
        self->w2ac = 0x3E;
    } else {
        self->w2ac = info->bf4;
        self->w2b4 = info->bfa;
    }

    if (self->w2a8 == self->w2ac) {
        s32 n;
        s32 v = self->w2b0;
        s32 k = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(self->w2a8);
        s32 c = (k == 0x28) ? 1 : getNumCharColor__6muMenuFiii(k);
        s32 b4;
        s32 cur = self->w2b0;
        do {
            n = v + 1;
            v = (n >= c) ? 0 : n;
        } while (cur == v || ((b4 = self->w2b4), b4 == v));
        s32 b = b4;
        do {
            n = b + 1;
            b = (n >= c) ? 0 : n;
        } while (cur == b || b4 == b || v == b);
        self->w2b0 = v;
        self->w2b4 = b;
    } else {
        s32 k = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(self->w2a8);
        s32 c = (k == 0x28) ? 1 : getNumCharColor__6muMenuFiii(k);
        s32 n = self->w2b0 + 1;
        self->w2b0 = (n >= c) ? 0 : n;
        if (self->w2ac != 0x3E) {
            s32 k2 = exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(self->w2ac);
            s32 c2 = (k2 == 0x28) ? 1 : getNumCharColor__6muMenuFiii(k2);
            s32 m = self->w2b4 + 1;
            self->w2b4 = (m >= c2) ? 0 : m;
        }
    }

    self->w260 = 0;
    self->w264 = 0;
    for (s32 i = 0; i < 0x2C; i++) {
        if (i != self->w2a8 && i != self->w2ac) {
            if (!((s64)(1 << i) & 0xFFFFFFFFC0068010LL)) {
                if (fn_8005227C(self->info->w40, self->info->w44, i) != 0) {
                    self->arr268[self->w260] = (u8)i;
                    self->w260 = self->w260 + 1;
                }
            }
        }
    }

    fn_27_254360(self, 0xFF);
    switch (self->info->kind) {
    case 5:
        self->w25c = (self->w1b8 == 1) ? lbl_27_data_52980[0] : lbl_27_data_52980[1];
        self->bd3 = 1;
        self->w100 = 3;
        self->w1b4 = 2;
        break;
    case 6:
        self->w25c = (self->w1b8 == 1) ? lbl_27_data_52980[2] : lbl_27_data_52980[3];
        self->bd3 = 1;
        self->w100 = 3;
        self->w1b4 = 2;
        break;
    case 7:
        self->w25c = (self->w1b8 == 1) ? lbl_27_data_52980[4] : lbl_27_data_52980[5];
        self->wf8 = 2;
        self->w100 = 3;
        break;
    case 8:
        self->w25c = (self->w1b8 == 1) ? lbl_27_data_52980[6] : lbl_27_data_52980[7];
        self->wf8 = 2;
        self->w100 = 3;
        break;
    case 9:
        self->w25c = (self->w1b8 == 1) ? lbl_27_data_52980[8] : lbl_27_data_52980[9];
        break;
    case 10:
        self->w25c = (self->w1b8 == 1) ? lbl_27_data_52980[10] : lbl_27_data_52980[11];
        break;
    }
}
