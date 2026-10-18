#pragma force_active on
typedef unsigned int u32;

typedef struct Obj {
    void *vtbl;
    u32 pad[3];
    u32 f10;
    u32 f14;
    u32 f18;
} Obj;

extern char lbl_102_data_1984[];

extern "C" {
void fn_102_7C34(Obj *p, u32 a, u32 b, u32 c)
{
    p->vtbl = lbl_102_data_1984;
    p->f10 = a;
    p->f14 = b;
    p->f18 = c;
}
}
