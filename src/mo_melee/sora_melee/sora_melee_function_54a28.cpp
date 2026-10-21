#pragma force_active on

struct Elem {
    int a;
    int b;
    short c;
    short d;
};

struct Source {
    int a;
    int b;
    short c;
    short d;
};

struct Container {
    virtual void slot00();
    virtual Elem* at(int index);
    virtual void slot08();
    virtual int size();
};

extern "C" void fn_27_54A28(Container* self, int start, const Source* source, unsigned int count) {
    int limit = static_cast<int>(count);
    if (limit + start >= self->size()) {
        limit = self->size() - start;
    }
    for (int i = 0; i < limit; ++i) {
        Elem* dst = self->at(start + i);
        dst->a = source->a;
        dst->b = source->b;
        dst->c = source->c;
        dst->d = source->d;
    }
}
