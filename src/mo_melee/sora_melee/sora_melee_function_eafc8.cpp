#pragma force_active on

struct Elem {
    unsigned char f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
    unsigned int f10;
    unsigned int f14;
    unsigned int f18;
    unsigned int f1C;
    unsigned int f20;
    unsigned int f24;
    unsigned int f28;
    unsigned int f2C;
    unsigned int f30;
    float f34;
    unsigned int f38;
    unsigned char f3C;
};

struct Container {
    virtual void slot08();
    virtual Elem* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_EAFC8(Container* self, int start, const Elem* source, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }
    for (int i = 0; i < limit; ++i) {
        Elem* dst = self->at(start + i);
        dst->f0 = source->f0;
        dst->f4 = source->f4;
        dst->f8 = source->f8;
        dst->fC = source->fC;
        dst->f10 = source->f10;
        dst->f14 = source->f14;
        dst->f18 = source->f18;
        dst->f1C = source->f1C;
        dst->f20 = source->f20;
        dst->f24 = source->f24;
        dst->f28 = source->f28;
        dst->f2C = source->f2C;
        dst->f30 = source->f30;
        dst->f34 = source->f34;
        dst->f38 = source->f38;
        dst->f3C = source->f3C;
    }
}