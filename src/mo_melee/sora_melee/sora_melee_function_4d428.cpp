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
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    float t;
    float u;
    float v;
    int w;
    int x;
    int y;
    int z;
    int aa;
    int ab;
    short ac;
    char ad;
    char ae;
    char af;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_27_4D428(Container* self, int start, const Data* src, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        Data* dst = self->at(start + i);
        *dst = *src;
    }
}
