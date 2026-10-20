#pragma force_active on
typedef unsigned char u8;
struct FlagsB4 { u8 a:2; u8 b:1; u8 c:5; };
struct FlagsB3 { u8 a:5; u8 b:1; u8 c:2; };
struct Obj {
    u8 pad[0x44];
    u8 *data;
};

extern "C" void fn_27_256838(Obj *self) {
    u8 v;
    int off = 0;
    for (int i = 0; i < 7; i++) {
        u8 *p = self->data + off;
        if (p[0x99] != 3) {
            v = 0;
            u8 idx = p[0x9a];
            if (((FlagsB4 *)(p + 0xb4))->b) {
                if (!((FlagsB3 *)(p + 0xb3))->b) {
                    v = 1;
                }
            }
            ((u8 *)self)[0x72 + idx] = v;
        }
        off += 0x5c;
    }
}
