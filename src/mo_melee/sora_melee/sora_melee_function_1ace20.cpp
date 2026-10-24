#pragma force_active on
struct soKineticEnergy;
template<class T> struct soInstanceUnitFullProperty {
    soInstanceUnitFullProperty(const T&, long, const short&, short);
    int b[3];
};
struct Sub {
    virtual void v0(); virtual void v1();
    virtual char* get(int);
    virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8();
    virtual void v9(); virtual void v10();
    virtual void set(int, soInstanceUnitFullProperty<soKineticEnergy*>*);
    virtual void v12(); virtual void v13();
    virtual unsigned int full();
};
struct Outer {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int count();
    virtual void v5();
    virtual unsigned int check(int);
    char pad0[0xC];
    Sub sub;
    char pad[0xAC - 0x14];
    unsigned char flag;
    inline int find(short b) {
        if (b <= -1) return count();
        int n = count();
        for (int i = 0; i < n; i++) {
            int v = *(short*)(sub.get(i) + 0xa);
            if (v <= -1) return i;
            if (v > b) return i;
        }
        return n;
    }
};
extern "C" int fn_27_1AD58C(Outer*);
extern "C" int fn_27_1ACE20(Outer* self, soKineticEnergy* const* e, int a, short* s, short b)
{
    if (self->sub.full() == 1U) return -1;
    if ((self->flag == 0 || a > -1) && self->check(a) == 1U) return -1;
    if (self->flag == 0 && a <= -1) {
        a = fn_27_1AD58C(self);
        if (a <= -1) return -1;
    }
    int idx = self->find(b);
    if (idx < 0) return -1;
    short t = *s;
    soInstanceUnitFullProperty<soKineticEnergy*> p(*e, a, t, b);
    self->sub.set(idx, &p);
    return a;
}
