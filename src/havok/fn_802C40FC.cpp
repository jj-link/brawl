#pragma force_active on

class Inner {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(unsigned int);
};

class Obj {
public:
    virtual void fn_a(int);
    int unk4;
    Inner* unk8;
    unsigned short unkC;
};

extern "C" void fn_802C40FC(Obj* arg0) {
    unsigned int id = arg0->unkC;
    if (id != 0xFFFF) {
        arg0->unk8->slot4(id);
    }
    if (arg0 != 0) {
        arg0->fn_a(1);
    }
}
