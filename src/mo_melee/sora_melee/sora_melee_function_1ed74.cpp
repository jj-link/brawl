#pragma force_active on

struct Elem {
    int a;
    float b;
    float c;
    unsigned char d;
    unsigned char e;
    unsigned char f;
    unsigned char g;
};

struct Container {
    virtual void slot08();
    virtual Elem* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1ED74(Container* self, int start, const Elem* value, unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Elem* dst = self->at(start + i);
        if (dst != value) {
            dst->a = value->a;
            dst->b = value->b;
            dst->c = value->c;
            dst->d = value->d;
            dst->e = value->e;
            dst->f = value->f;
            dst->g = value->g;
        }
    }
}
