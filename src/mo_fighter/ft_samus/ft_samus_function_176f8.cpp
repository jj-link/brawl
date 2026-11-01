#pragma force_active on
extern "C" void fn_27_13138C(void*);

class Class_CF88 {
public:
    virtual void fn_94_6CF8();
    virtual void fn_94_1CAF0();
    virtual void fn_94_1DAE0();
    virtual void fn_94_1DAD8();
    virtual void fn_94_1DAD0();
    virtual void fn_94_1DAC8();
    virtual void fn_94_1DAC0(unsigned short, int, unsigned short);
    virtual void fn_94_1DAB8();
    virtual void fn_94_1DAB0();
    virtual void fn_94_1DAA8(int, int, int);
    virtual void fn_94_1DAA0();
    virtual void fn_94_1DA98();
    virtual void fn_94_1DA90();
    virtual void fn_94_1DA88();
    virtual void fn_94_1DA38();
    virtual void fn_94_1DA80(int, int);
    virtual void fn_94_1DA70(int, int);
    virtual void fn_94_1DA60();
    virtual int fn_94_1DA50(int);
};

struct StructC {
    char pad[0x84];
    Class_CF88* obj;
};

struct StructB {
    char pad[0xD8];
    StructC* sc;
};

struct StructA {
    char pad[0x60];
    StructB* sb;
};

extern "C" void fn_94_176F8(void* arg0, int arg1, int arg2) {
    fn_27_13138C(arg0);

    Class_CF88* obj = ((StructA*)arg0)->sb->sc->obj;

    if (arg2 == 0x2C || arg2 == 0x32 || arg2 == 0x33 || arg2 == 0x35 ||
        arg2 == 0x37 || arg2 == 0x3C || arg2 == 0x10C || arg2 == 0x10F) {
        obj->fn_94_1DA70(2, 0);
    } else if ((unsigned)(arg2 - 0x113) <= 1) {
        if (arg1 != 0x81 && arg1 != 0x80) {
            obj->fn_94_1DA70(2, 0);
        }
    } else if (arg2 == 0x34 || arg2 == 0x36 || arg2 == 0x38) {
        if (arg1 != 0x35 && arg1 != 0x37) {
            obj->fn_94_1DA70(2, 0);
        }
    }

    if (obj->fn_94_1DA50(0) != 0) {
        if (arg1 == 0xBD) {
            obj->fn_94_1DA80(0, 0);
        } else {
            if (arg1 != 0x81 && arg1 != 0x80 && arg1 != 0x82 &&
                arg1 != 0x83 && arg1 != 0x35 && arg1 != 0x37) {
                unsigned short a = 0;
                obj->fn_94_1DAC0(a, -1, a);
            }
            obj->fn_94_1DAA8(0, 0, 0);
        }
    }
}
