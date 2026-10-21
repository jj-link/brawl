#pragma force_active on

struct Entry {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void slot00();
    virtual Entry* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_B10F0(Container* self, int start, const Entry* value,
                            unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Entry* dst = self->at(start + i);
        dst->a = value->a;
        dst->b = value->b;
        dst->c = value->c;
        dst->d = value->d;
    }
}
