#pragma force_active on

struct Value {
    int a00;
    int a04;
    int a08;
    int a0C;
    float f10;
    int a14;
    int a18;
    int a1C;
    int a20;
    float f24;
    float f28;
    float f2C;
    int a30;
    int a34;
    int a38;
    int a3C;
    int a40;
    int a44;
    int a48;
    int a4C;
    int a50;
    int a54;
    int a58;
    unsigned short s5C;
    unsigned char b5E;
    unsigned char b5F;
    int a60;
    unsigned char b64;
};

struct Array {
    virtual void dummy();
    virtual Value* at(int);
    virtual void dummy2();
    virtual int size();
};

extern "C" void fn_27_DF8D0(Array* self, int start, const Value* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Value* dst = self->at(start + i);
        dst->a00 = src->a00;
        dst->a04 = src->a04;
        dst->a08 = src->a08;
        dst->a0C = src->a0C;
        dst->f10 = src->f10;
        dst->a14 = src->a14;
        dst->a18 = src->a18;
        dst->a1C = src->a1C;
        dst->a20 = src->a20;
        dst->f24 = src->f24;
        dst->f28 = src->f28;
        dst->f2C = src->f2C;
        dst->a30 = src->a30;
        dst->a34 = src->a34;
        dst->a38 = src->a38;
        dst->a3C = src->a3C;
        dst->a40 = src->a40;
        dst->a44 = src->a44;
        dst->a48 = src->a48;
        dst->a4C = src->a4C;
        dst->a50 = src->a50;
        dst->a54 = src->a54;
        dst->a58 = src->a58;
        dst->s5C = src->s5C;
        dst->b5E = src->b5E;
        dst->b5F = src->b5F;
        dst->a60 = src->a60;
        dst->b64 = src->b64;
    }
}
