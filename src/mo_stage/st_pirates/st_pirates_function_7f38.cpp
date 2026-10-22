#pragma force_active on
struct Data {
    int a[19];
    float f[3];
    int b[6];
    short s;
    unsigned char c0, c1, c2;
};

struct Container {
    virtual void slot08();
    virtual Data* at(int index);
    virtual void slot10();
    virtual int size();
};

extern "C" void fn_52_7F38(Container* self, int start, const Data* v, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->size())
        count = self->size() - start;
    for (int i = 0; i < count; ++i) {
        Data* d = self->at(start + i);
        d->a[0]=v->a[0]; d->a[1]=v->a[1]; d->a[2]=v->a[2]; d->a[3]=v->a[3];
        d->a[4]=v->a[4]; d->a[5]=v->a[5]; d->a[6]=v->a[6]; d->a[7]=v->a[7];
        d->a[8]=v->a[8]; d->a[9]=v->a[9]; d->a[10]=v->a[10]; d->a[11]=v->a[11];
        d->a[12]=v->a[12]; d->a[13]=v->a[13]; d->a[14]=v->a[14]; d->a[15]=v->a[15];
        d->a[16]=v->a[16]; d->a[17]=v->a[17]; d->a[18]=v->a[18];
        d->f[0]=v->f[0]; d->f[1]=v->f[1]; d->f[2]=v->f[2];
        d->b[0]=v->b[0]; d->b[1]=v->b[1]; d->b[2]=v->b[2];
        d->b[3]=v->b[3]; d->b[4]=v->b[4]; d->b[5]=v->b[5];
        d->s=v->s; d->c0=v->c0; d->c1=v->c1; d->c2=v->c2;
    }
}
