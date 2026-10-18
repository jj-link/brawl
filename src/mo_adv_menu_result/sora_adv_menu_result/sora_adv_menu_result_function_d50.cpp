#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct Param {
    u32 a, b, c, d, e, f, g, h;
    unsigned char port;
    unsigned char pad[3];
    void* p1;
    void* p2;
    void* p3;
};

struct Pair {
    union {
        bool flag;
        u32 word;
    } a;
    u32 b;
};

struct Adv {
    char pad[0x4928];
    u32 a, b;
};

struct Global {
    char pad[0x30];
    Adv* adv;
};

struct Obj {
    char pad0[0x114];
    u32 a;
    char pad118[4];
    u32 b;
    char pad120[0x10];
    u32 c, d;
    char pad138[0x464];
    void* result;
    char pad5a0[8];
    void* resource;
};

extern "C" {
extern const Param lbl_34_rodata_58;
extern Global* g_GameGlobal;

void* fn_80015DB4(void*, int, int, int, u16);
void* fn_800F7CCC(Param*, int, int);

void fn_34_D50(Obj* self) {
    Param param = lbl_34_rodata_58;
    param.a = self->c;
    param.b = self->d;
    param.e = self->a;
    param.f = self->b;

    Pair fallback;
    Pair value;
    Pair copy;

    Adv* adv = g_GameGlobal->adv;
    if (adv) {
        value.a.word = adv->a;
        value.b = adv->b;
    } else {
        fallback.a.flag = false;
        fallback.b = -1;
        value = fallback;
    }

    copy = value;
    param.port = copy.b;
    param.p1 = fn_80015DB4(self->resource, 0, 1, 40, (u16)0xFFFE);
    param.p2 = fn_80015DB4(self->resource, 0, 1, 50, (u16)0xFFFE);
    param.p3 = fn_80015DB4(self->resource, 0, 1, 60, (u16)0xFFFE);
    self->result = fn_800F7CCC(&param, 43, 43);
}
}
