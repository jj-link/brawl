#pragma force_active on
typedef unsigned int u32;

void fn_801F0C08(int arg0, int arg1, u32 *arg2) {
    union {
        u32 u;
        struct {
            u32 top : 10;
            u32 b : 10;
            u32 a : 10;
            u32 pad : 2;
        } f;
    } v;
    v.u = 0xC8000000u;
    v.f.a = arg0;
    v.f.b = arg1;
    *arg2 = *(u32 *)v.u;
}
