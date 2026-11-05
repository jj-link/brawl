#pragma force_active on
extern "C" const float lbl_94_rodata_90;

class Class_CE08 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CB4C();
    virtual void fn_94_1D91C();
    virtual void fn_94_1D918();
    virtual int fn_94_1D914(int);
    virtual void fn_94_1D910(int, int);
    virtual void fn_94_1D908();
    virtual void fn_94_1D950();
    virtual void fn_94_1D948();
    virtual void fn_94_1D940();
    virtual void fn_94_1D938();
    virtual void fn_94_1D930();
    virtual void fn_94_1D8C8();
    virtual void fn_94_1D8FC(float, int);
    virtual void fn_94_1D8F0();
    virtual void fn_94_1D8E8();
    virtual void fn_94_1D8DC();
};

class Class_CF88 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CAF0();
    virtual void fn_94_1DAE0();
    virtual void fn_94_1DAD8();
    virtual void fn_94_1DAD0();
    virtual void fn_94_1DAC8();
    virtual void fn_94_1DAC0();
    virtual void fn_94_1DAB8();
    virtual void fn_94_1DAB0();
    virtual void fn_94_1DAA8();
    virtual void fn_94_1DAA0();
    virtual void fn_94_1DA98();
    virtual void fn_94_1DA90();
    virtual void fn_94_1DA88();
    virtual void fn_94_1DA38();
    virtual void fn_94_1DA80();
    virtual void fn_94_1DA70(int, int);
};

struct StructC {
    char pad[0x44];
    Class_CF88* obj44;
    char pad2[0x1C];
    Class_CE08* obj64;
};

struct StructB {
    char pad[0xD8];
    StructC* sc;
};

struct StructA {
    char pad[0x60];
    StructB* sb;
};

extern "C" int fn_94_1D668(StructA* arg0) {
    int r = arg0->sb->sc->obj64->fn_94_1D914(0x10000008);
    if (r > 0) {
        arg0->sb->sc->obj44->fn_94_1DA70(r, 0);
        arg0->sb->sc->obj64->fn_94_1D8FC(lbl_94_rodata_90, 0x11000001);
        arg0->sb->sc->obj64->fn_94_1D910(0, 0x10000008);
    }
    return 0;
}
