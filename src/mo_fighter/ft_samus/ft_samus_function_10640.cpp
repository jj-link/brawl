#pragma force_active on

class Class_Z;

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
    virtual int fn_94_1DA70();
    virtual void fn_94_1DA60();
    virtual void fn_94_1DA50();
    virtual void fn_94_1DA40();
    virtual void fn_94_1DA28();
};

class Class_X {
public:
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1c();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c();
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual int s4c(unsigned int);
    virtual void s50();
    virtual void s54(unsigned int);
};

class Class_Y {
public:
    virtual void s08();
    virtual void s0c();
    virtual void s10();
    virtual Class_Z* s14(int, bool, bool);
    virtual void s18();
    virtual void s1c(bool, bool, bool);
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2c();
    virtual void s30();
    virtual void s34();
    virtual void s38();
    virtual void s3c(Class_Z*);
    virtual void s40();
    virtual void s44();
    virtual void s48();
    virtual void s4c();
    virtual void s50();
    virtual void s54();
    virtual int s58(int);
};

class Class_Z {
public:
    virtual int s08();
};

struct Access {
    unsigned char pad0[0x64];
    Class_X* x;
    unsigned char pad1[0x70 - 0x68];
    Class_CF88* cf;
    unsigned char pad2[0x84 - 0x74];
    Class_Y* y;
};

struct Owner {
    unsigned char pad[0xd8];
    Access* access;
};

extern "C" void fn_94_10640(void*, void* arg) {
    Owner* o = (Owner*)arg;
    Class_CF88* cf = o->access->cf;
    int r = cf->fn_94_1DA70();
    Class_X* x = o->access->x;
    if (r != 0x121) {
        if (x->s4c(0x22000014) != 0) {
            Class_Y* y = o->access->y;
            if (y->s58(1) != 0) {
                Class_Z* z = y->s14(1, false, false);
                if (z->s08() == 0) {
                    y->s3c(z);
                    y->s1c(true, false, true);
                }
            }
            x->s54(0x22000014);
        }
    }
}
