#pragma force_active on

class Class_8DBC {
public:
    virtual void fn_95_8008();       // 0x08
    virtual void fn_95_16C80();      // 0x0c
    virtual void fn_95_17664(int, int); // 0x10
    virtual void fn_95_1765C();      // 0x14
    virtual int fn_95_17654(int);    // 0x18
    virtual void fn_95_1764C(int, int); // 0x1c
    virtual void fn_95_17644();      // 0x20
    virtual void fn_95_1763C();      // 0x24
    virtual void fn_95_17634();      // 0x28
    virtual void fn_95_1762C();      // 0x2c
    virtual void fn_95_17624();      // 0x30
    virtual void fn_95_1761C();      // 0x34
    virtual void fn_95_17614();      // 0x38
    virtual void fn_95_1760C();      // 0x3c
    virtual void fn_95_175BC();      // 0x40
    virtual void fn_95_17604();      // 0x44
    virtual void fn_95_175F4();      // 0x48
    virtual int fn_95_175D4(int);    // 0x4c
    virtual void fn_95_175B4();      // 0x50
    virtual void fn_95_175C4(int);   // 0x54
};

struct Mods {
    void* pad00_58[0x58 / 4];
    Class_8DBC* mod58; // 0x58
    void* pad5c[2];
    Class_8DBC* mod64; // 0x64
};

struct Outer {
    void* pad[0xD8 / 4];
    Mods* mods; // 0xD8
};

extern int lbl_95_data_7FA0[15];

extern "C" void fn_95_FF04(Outer* arg0) {
    Class_8DBC* work = arg0->mods->mod64;
    int a = work->fn_95_175D4(0x22000011);
    int b = work->fn_95_175D4(0x22000012);
    int counter = work->fn_95_17654(0x20000001);
    int sub = work->fn_95_17654(0x20000007);
    if (b != 0) {
        counter = 0;
        sub = sub + 1;
    } else if (a != 0) {
        counter = counter + 1;
    }
    if (counter >= 0 && counter < 14) {
        arg0->mods->mod58->fn_95_17664(1, lbl_95_data_7FA0[counter]);
        if (b != 0) {
            work->fn_95_175C4(0x22000011);
            work->fn_95_175C4(0x22000012);
            counter = -1;
        }
    } else {
        work->fn_95_175C4(0x22000011);
        work->fn_95_175C4(0x22000012);
    }
    work->fn_95_1764C(counter, 0x20000001);
    work->fn_95_1764C(sub, 0x20000007);
}
