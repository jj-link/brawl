#pragma force_active on

struct Elem {
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned char e;
    unsigned char f;
    unsigned char g;
    unsigned char h;
    unsigned char i;
};

struct Container {
    virtual void slot08();
    virtual Elem* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_1230B0(Container* self, int start, const Elem* source, unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size()) {
        count = self->size() - start;
    }

    for (int i = 0; i < count; ++i) {
        Elem* dst = self->at(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
        dst->d = source->d;
        dst->e = source->e;
        dst->f = source->f;
        dst->g = source->g;
        dst->h = source->h;
        dst->i = source->i;
    }
}
