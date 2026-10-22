#pragma force_active on

struct Data {
    int w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16, w17, w18;
    float f0, f1, f2;
    int x0, x1, x2, x3, x4, x5;
    short s0;
    unsigned char c0, c1, c2;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_57_B740(Container* self, int start, const Data* value, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size()) {
        count = self->size() - start;
    }

    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        dst->w0 = value->w0;
        dst->w1 = value->w1;
        dst->w2 = value->w2;
        dst->w3 = value->w3;
        dst->w4 = value->w4;
        dst->w5 = value->w5;
        dst->w6 = value->w6;
        dst->w7 = value->w7;
        dst->w8 = value->w8;
        dst->w9 = value->w9;
        dst->w10 = value->w10;
        dst->w11 = value->w11;
        dst->w12 = value->w12;
        dst->w13 = value->w13;
        dst->w14 = value->w14;
        dst->w15 = value->w15;
        dst->w16 = value->w16;
        dst->w17 = value->w17;
        dst->w18 = value->w18;
        dst->f0 = value->f0;
        dst->f1 = value->f1;
        dst->f2 = value->f2;
        dst->x0 = value->x0;
        dst->x1 = value->x1;
        dst->x2 = value->x2;
        dst->x3 = value->x3;
        dst->x4 = value->x4;
        dst->x5 = value->x5;
        dst->s0 = value->s0;
        dst->c0 = value->c0;
        dst->c1 = value->c1;
        dst->c2 = value->c2;
    }
}
