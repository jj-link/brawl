#pragma force_active on

struct Element {
    unsigned int a0, a1, a2, a3, a4, a5;
    unsigned int a6, a7, a8, a9, a10, a11;
};

struct Array {
    virtual void v08();
    virtual Element* at(int);
    virtual void v10();
    virtual int size();
};

extern "C" void fn_27_E025C(Array* self, int start,
                            const Element* value, long countArg) {
    int count = countArg;
    if (count + start >= self->size()) {
        count = self->size() - start;
    }
    for (int i = 0; i < count; ++i) {
        *self->at(start + i) = *value;
    }
}
