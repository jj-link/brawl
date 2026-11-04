#pragma force_active on

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(unsigned int);
};

class Obj {
public:
    virtual void v0(int);
    int unk4;
    Inner* unk8;
    unsigned short unkC;
};

extern "C" void fn_802C25D0(Obj* arg0) {
    unsigned int id = arg0->unkC;
    if (id != 0xFFFF) {
        arg0->unk8->v4(id);
    }
    if (arg0 != 0) {
        arg0->v0(1);
    }
}