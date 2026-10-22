#pragma force_active on
typedef unsigned char u8;

struct Child {
    char pad[0x6C];
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
    u8 b6:1;
    u8 b7:1;
};

struct Flags54 {
    u8 b0:1;
    u8 b1:1;
    u8 b2:1;
    u8 b3:1;
    u8 b4:1;
    u8 b5:1;
    u8 b6:1;
    u8 b7:1;
};

struct Obj {
    char pad[0x54];
    Flags54 f54;
    Flags54 f55;
    Flags54 f56;
    char pad57;
    Child* f58;
};

extern "C" void fn_801139E4(Obj* arg0) {
    if (arg0 == 0) {
        return;
    }
    if (arg0->f54.b2) {
        arg0->f54.b1 = 1;
        arg0->f54.b2 = 0;
    }
    arg0->f54.b3 = arg0->f54.b1;
    arg0->f55.b0 = arg0->f54.b7;
    if (arg0->f56.b0 != 1) {
        Child* c = arg0->f58;
        arg0->f54.b6 = 0;
        if (c != 0) {
            if (c->b2) {
                Flags54 t;
                *(u8*)&t = (u8)(*(u8*)&arg0->f54 | 0x10);
                t.b1 = t.b3;
                *(u8*)&arg0->f54 = *(u8*)&t;
            } else {
                Flags54 t;
                *(u8*)&t = (u8)(*(u8*)&arg0->f54 & 0x7F);
                t.b3 = t.b0;
                t.b1 = t.b3;
                *(u8*)&arg0->f54 = *(u8*)&t;
            }
            arg0->f54.b3 = arg0->f54.b1;
        }
    }
}
