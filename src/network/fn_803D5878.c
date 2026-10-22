#pragma force_active on
extern void* memset(void*, int, unsigned long);
typedef struct {
    int type;
    int x4;
    void* buf;
    unsigned short count;
    unsigned short xe;
    union {
        struct { unsigned char a, b, c, d; } u8;
        struct { unsigned short h; unsigned char c, d; } u16;
        struct { unsigned pad : 2; unsigned f : 15; unsigned rest : 15; } bf;
        unsigned w;
    } u;
    int x14;
} Obj;

void fn_803D5878(Obj* o, int type, void* buf, unsigned short count) {
    if (o == 0) return;
    if (buf == 0) return;
    o->type = type;
    o->x4 = 0;
    o->count = count;
    o->buf = buf;
    o->xe = 0;
    o->u.w = 0;
    o->x14 = 0;
    switch (type) {
    case 3:
        if (count > 100) return;
        o->u.u8.a = 2;
        o->u.u8.b = 3;
        o->u.u8.c = 3;
        break;
    case 1:
    case 2:
        if (count > 10000) return;
        o->u.bf.f = -1;
        break;
    case 0:
        o->u.u16.h = 0;
        o->u.u16.c = 2;
        break;
    }
    memset(o->buf, 0, o->count << 6);
}
