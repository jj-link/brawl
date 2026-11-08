#pragma force_active on

struct Data {
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    float j;
    int k;
    int l;
    int m;
    int n;
    int o;
    float p;
};

struct Container {
    virtual void slot00();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_3909A8(Container* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        *dst = *src;
    }
}