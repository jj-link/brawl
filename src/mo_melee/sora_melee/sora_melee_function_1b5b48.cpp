#pragma force_active on

struct Elem {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char e;
};

struct Container {
    virtual void slot08();
    virtual Elem* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1B5B48(Container* self, int start, const Elem* value, unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size()) {
        count = self->size() - start;
    }

    for (int i = 0; i < count; ++i) {
        Elem* dst = self->at(start + i);
        dst->a = value->a;
        dst->b = value->b;
        dst->c = value->c;
        dst->d = value->d;
        dst->e = value->e;
    }
}
