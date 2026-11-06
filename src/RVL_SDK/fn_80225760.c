#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Obj {
    u32 w0;
    u32 w4;
    u32 w8;
    u8 pad0C[0x60 - 0x0C];
    u32 w60;
    u32 w64;
    u32 w68;
    u8 pad6C[0x4CC - 0x6C];
    u16 h4cc;
    u16 h4ce;
    u16 h4d0;
    u16 h4d2;
    u16 h4d4;
    u16 h4d6;
} Obj;

void fn_80225760(Obj *o, u32 arg1, s32 arg2) {
    if (o->w4 != 0 || o->w8 != 0) {
        o->h4cc = 0;
        o->h4ce = o->h4d0;
        if (o->w4 != 0 && o->h4d2 != 0) {
            o->w0 |= 0x80000000;
        }
    } else if (o->w0 != 0) {
        u16 a;
        u16 r8;
        u32 b;
        a = o->h4cc + arg2;
        o->h4cc = a;
        if (a >= 0x9C40) {
            o->h4cc = a - 0x9C40;
        }
        r8 = o->h4cc;
        if (r8 >= o->h4ce) {
            o->w0 |= 0x80000000;
            b = o->h4ce + o->h4d2;
            o->h4ce = b;
            if (r8 >= 0x4E20) {
                o->h4cc = r8 - 0x4E20;
                o->h4ce = (u16)b - 0x4E20;
            }
        }
    }

    if (arg1 != 2) {
        return;
    }

    if (o->w64 != 0 || o->w68 != 0) {
        o->h4d4 = 0;
        o->h4d6 = o->h4d0;
        if (o->w64 != 0 && o->h4d2 != 0) {
            o->w60 |= 0x80000000;
        }
    } else if (o->w60 != 0) {
        u16 a;
        u16 r6;
        u32 b;
        a = o->h4d4 + arg2;
        o->h4d4 = a;
        if (a >= 0x9C40) {
            o->h4d4 = a - 0x9C40;
        }
        r6 = o->h4d4;
        if (r6 >= o->h4d6) {
            o->w60 |= 0x80000000;
            b = o->h4d6 + o->h4d2;
            o->h4d6 = b;
            if (r6 >= 0x4E20) {
                o->h4d4 = r6 - 0x4E20;
                o->h4d6 = (u16)b - 0x4E20;
            }
        }
    }
}
