#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Fn27Obj {
    u32 count;
    u8 pad[0xC];
    float f10;
    u32 w14;
    struct {
        u32 a : 4;
        u32 b : 1;
        u32 c : 1;
        u32 d : 26;
    } w18;
};

extern "C" {
extern const float lbl_27_rodata_4F8;
void fn_27_55E8C(u32 a, u32 b, u32 c, u32 d, u32 e, Fn27Obj* f, float g, float h);

void fn_27_4B088(Fn27Obj* p, u32 a, u32 b, float f)
{
    if (p->count == 0) {
        return;
    }
    fn_27_55E8C(a, b, p->count - 1 == 0, p->w18.c, p->w14 >> 23, (Fn27Obj*)((u8*)p + 4), p->f10, (p->w18.b == 0) ? f : lbl_27_rodata_4F8);
}
}
