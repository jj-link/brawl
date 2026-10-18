#pragma force_active on
class Obj {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
};

extern "C" int fn_94_199F8(void *arg)
{
    Obj *o = (Obj *)((char *)arg + 0x19700);
    return o->f2();
}
