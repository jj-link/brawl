#pragma force_active on

struct Data {
    int a00, a04, a08, a0C, a10, a14, a18, a1C, a20, a24, a28, a2C, a30, a34, a38, a3C, a40, a44, a48;
    float f4C, f50, f54;
    int a58, a5C, a60, a64, a68, a6C;
    short s70;
    unsigned char b72, b73, b74;
};

struct Container {
    virtual void slot00();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_76_60C0(Container* self, int start, const Data* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size()) {
        count = self->size() - start;
    }

    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        dst->a00 = source->a00;
        dst->a04 = source->a04;
        dst->a08 = source->a08;
        dst->a0C = source->a0C;
        dst->a10 = source->a10;
        dst->a14 = source->a14;
        dst->a18 = source->a18;
        dst->a1C = source->a1C;
        dst->a20 = source->a20;
        dst->a24 = source->a24;
        dst->a28 = source->a28;
        dst->a2C = source->a2C;
        dst->a30 = source->a30;
        dst->a34 = source->a34;
        dst->a38 = source->a38;
        dst->a3C = source->a3C;
        dst->a40 = source->a40;
        dst->a44 = source->a44;
        dst->a48 = source->a48;
        dst->f4C = source->f4C;
        dst->f50 = source->f50;
        dst->f54 = source->f54;
        dst->a58 = source->a58;
        dst->a5C = source->a5C;
        dst->a60 = source->a60;
        dst->a64 = source->a64;
        dst->a68 = source->a68;
        dst->a6C = source->a6C;
        dst->s70 = source->s70;
        dst->b72 = source->b72;
        dst->b73 = source->b73;
        dst->b74 = source->b74;
    }
}
