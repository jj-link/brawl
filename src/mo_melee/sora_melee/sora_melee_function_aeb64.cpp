#pragma force_active on

struct Element {
    unsigned int a;
    unsigned int b;
    unsigned char c;
};

struct Container {
    virtual void slot08();
    virtual Element* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_AEB64(Container* self, int start, const Element* value,
                             unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;

    int i = 0;
    while (i < count) {
        Element* dst = self->at(start + i);
        dst->a = value->a;
        dst->b = value->b;
        dst->c = value->c;
        ++i;
    }
}
