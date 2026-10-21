#pragma force_active on

struct Data {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void slot00();
    virtual Data* at(int index);
    virtual void slot02();
    virtual int size();
};

extern "C" void fn_27_101E50(Container* self, int start, const Data* value, unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;
    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        dst->a = value->a;
        dst->b = value->b;
        dst->c = value->c;
        dst->d = value->d;
    }
}
