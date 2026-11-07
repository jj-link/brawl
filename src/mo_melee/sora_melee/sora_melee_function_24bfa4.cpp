#pragma force_active on
typedef unsigned char u8;
struct E { u8 a[0x25]; u8 k; u8 b[0xc]; u8 v0; u8 v1; u8 c[0x2ac-0x34]; };
struct H { u8 a[0x1304]; u8 v0; u8 v1; u8 f; u8 pad[0x30-3]; };
extern "C" void fn_27_24BFA4(H* p) {
    if (((u8*)p)[0xf] > 1) {
        E* e = (E*)p;
        for (int i = 0; i < 7; i++, e++) {
            if (e->a[0x25] != 3 && e->v0 == 0) e->v0 = e->v1;
        }
    }
    if (((u8*)p)[0x10] > 1) {
        for (int i = 0; i < 3; i++) {
            if (p[0].f != 0 && p[0].v0 == 0) p[0].v0 = p[0].v1;
            p = (H*)((u8*)p + 0x30);
        }
    }
}