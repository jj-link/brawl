#pragma force_active on

struct Data {
    int a;
    int b;
    float c;
    float d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    unsigned char k;
    unsigned char l;
    unsigned char m;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_E9564(Container* self, int start, const Data* value,
                          unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        dst->a = value->a;
        dst->b = value->b;
        dst->c = value->c;
        dst->d = value->d;
        dst->e = value->e;
        dst->f = value->f;
        dst->g = value->g;
        dst->h = value->h;
        dst->i = value->i;
        dst->j = value->j;
        dst->k = value->k;
        dst->l = value->l;
        dst->m = value->m;
    }
}
