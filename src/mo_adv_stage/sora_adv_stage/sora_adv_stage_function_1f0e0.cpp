#pragma force_active on

struct Data {
    float f00, f04, f08, f0C;
    int a10, a14, a18, a1C, a20, a24, a28;
    unsigned short s2C, s2E;
    unsigned char b30, b31, b32, b33, b34, b35, b36, b37, b38, b39, b3A;
    int a3C, a40, a44, a48;
    float f4C;
    int a50, a54, a58, a5C;
    float f60, f64, f68;
    int a6C, a70, a74, a78;
    float f7C;
    int a80, a84, a88, a8C, a90;
    float f94;
    int a98;
    unsigned char b9C;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Data* slot1(int index);
    virtual void slot2();
    virtual int slot3();
};

extern "C" void fn_40_1F0E0(Object_vptr_0* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->slot3())
        count = self->slot3() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->slot1(start + i);
        dst->f00 = src->f00;
        dst->f04 = src->f04;
        dst->f08 = src->f08;
        dst->f0C = src->f0C;
        dst->a10 = src->a10;
        dst->a14 = src->a14;
        dst->a18 = src->a18;
        dst->a1C = src->a1C;
        dst->a20 = src->a20;
        dst->a24 = src->a24;
        dst->a28 = src->a28;
        dst->s2C = src->s2C;
        dst->s2E = src->s2E;
        dst->b30 = src->b30;
        dst->b31 = src->b31;
        dst->b32 = src->b32;
        dst->b33 = src->b33;
        dst->b34 = src->b34;
        dst->b35 = src->b35;
        dst->b36 = src->b36;
        dst->b37 = src->b37;
        dst->b38 = src->b38;
        dst->b39 = src->b39;
        dst->b3A = src->b3A;
        dst->a3C = src->a3C;
        dst->a40 = src->a40;
        dst->a44 = src->a44;
        dst->a48 = src->a48;
        dst->f4C = src->f4C;
        dst->a50 = src->a50;
        dst->a54 = src->a54;
        dst->a58 = src->a58;
        dst->a5C = src->a5C;
        dst->f60 = src->f60;
        dst->f64 = src->f64;
        dst->f68 = src->f68;
        dst->a6C = src->a6C;
        dst->a70 = src->a70;
        dst->a74 = src->a74;
        dst->a78 = src->a78;
        dst->f7C = src->f7C;
        dst->a80 = src->a80;
        dst->a84 = src->a84;
        dst->a88 = src->a88;
        dst->a8C = src->a8C;
        dst->a90 = src->a90;
        dst->f94 = src->f94;
        dst->a98 = src->a98;
        dst->b9C = src->b9C;
    }
}