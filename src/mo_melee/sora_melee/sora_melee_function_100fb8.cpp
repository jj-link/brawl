#pragma force_active on

struct Item {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void slot00();
    virtual Item* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_100FB8(Container* self, int start, const Item* src, unsigned int count)
{
    int limit = static_cast<int>(count);
    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }
    for (int i = 0; i < limit; ++i) {
        Item* dst = self->at(start + i);
        dst->a = src->a;
        dst->b = src->b;
        dst->c = src->c;
        dst->d = src->d;
    }
}
