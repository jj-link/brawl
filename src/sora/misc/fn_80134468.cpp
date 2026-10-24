#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Slot {
    u32 a;
    u32 b;
    u32 c;
    u8 d;
    u8 pad[3];
};

struct Obj {
    u8 pad0[0x75];
    u8 f3 : 1;
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f5 : 1;
    u8 f4 : 1;
    u8 f7 : 1;
    u8 f6 : 1;
    u8 pad1[0xD4 - 0x76];
    Slot slots[8];
};

extern "C" void fn_80134468(Obj* o, int i) {
    Slot* s = &o->slots[(u32)i];
    s->d = s->c = s->b = s->a = 0;
    switch ((u32)i) {
    case 0: o->f0 = 0; break;
    case 1: o->f1 = 0; break;
    case 2: o->f2 = 0; break;
    case 3: o->f3 = 0; break;
    case 5: o->f5 = 0; break;
    case 7: o->f7 = 0; break;
    case 4: o->f4 = 0; break;
    case 6: o->f6 = 0; break;
    }
}
