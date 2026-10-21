#pragma force_active on

struct Rec {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void s0();
    virtual Rec* at(int index);
    virtual void s2();
    virtual int size();
};

extern "C" void fn_27_103434(Container* self, int start, const Rec* src,
                            unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size()) {
        count = self->size() - start;
    }

    for (int i = 0; i < count; ++i) {
        Rec* dst = self->at(start + i);
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
    }
}
