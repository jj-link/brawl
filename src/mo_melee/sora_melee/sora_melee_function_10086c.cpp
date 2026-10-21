#pragma force_active on

struct Entry {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void slot08();
    virtual Entry* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_10086C(Container* self, int start,
                            const Entry* source, unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Entry* dst = self->at(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
        dst->d = source->d;
    }
}
