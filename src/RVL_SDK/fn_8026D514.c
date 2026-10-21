#pragma force_active on
typedef unsigned long u32;

struct Obj {
    char pad[0x14];
    u32 unk14;
};

void fn_8026D514(struct Obj *arg0, u32 *arg1)
{
    u32 temp = arg0->unk14;
    u32 quotient = temp >> 3;

    *arg1 += quotient;
    arg0->unk14 -= quotient << 3;
}
