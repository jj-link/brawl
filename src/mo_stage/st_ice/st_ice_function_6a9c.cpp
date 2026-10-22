#pragma force_active on

struct Data {
    int a00, a04, a08, a0C, a10, a14, a18, a1C, a20, a24, a28, a2C, a30, a34, a38, a3C, a40, a44, a48;
    float f4C, f50, f54;
    int a58, a5C, a60, a64, a68, a6C;
    short s70;
    unsigned char b72, b73, b74;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_62_6A9C(Container* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size()) {
        count = self->size() - start;
    }

    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        dst->a00 = src->a00;
        dst->a04 = src->a04;
        dst->a08 = src->a08;
        dst->a0C = src->a0C;
        dst->a10 = src->a10;
        dst->a14 = src->a14;
        dst->a18 = src->a18;
        dst->a1C = src->a1C;
        dst->a20 = src->a20;
        dst->a24 = src->a24;
        dst->a28 = src->a28;
        dst->a2C = src->a2C;
        dst->a30 = src->a30;
        dst->a34 = src->a34;
        dst->a38 = src->a38;
        dst->a3C = src->a3C;
        dst->a40 = src->a40;
        dst->a44 = src->a44;
        dst->a48 = src->a48;
        dst->f4C = src->f4C;
        dst->f50 = src->f50;
        dst->f54 = src->f54;
        dst->a58 = src->a58;
        dst->a5C = src->a5C;
        dst->a60 = src->a60;
        dst->a64 = src->a64;
        dst->a68 = src->a68;
        dst->a6C = src->a6C;
        dst->s70 = src->s70;
        dst->b72 = src->b72;
        dst->b73 = src->b73;
        dst->b74 = src->b74;
    }
}
