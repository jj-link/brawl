#pragma force_active on

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0(int, short*);
    virtual void fn_27_1412C();
    virtual void fn_27_14134(int);
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual int fn_27_14A38();
};

struct Target {
    virtual void slot0();
    virtual void slot1(int);
    unsigned char pad[1];
    unsigned char flag;
    unsigned char state;
};

struct Entry {
    Target* target;
};

class EntryArray {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Entry* slot2(int);
    virtual int slot3(int);
    virtual int slot4();
};

struct Outer {
    char pad0[0x14];
    EntryArray* entries;
    char pad18[0x14];
    Class_1250* module;
};

extern "C" void fn_27_B6EE0(Outer* arg0, int arg1, short* arg2) {
    if (*arg2 == -1) {
        arg0->module->fn_27_14068();
    } else {
        short value = *arg2;
        arg0->module->fn_27_140C0(arg1, &value);
    }

    EntryArray* entries = arg0->entries;
    int count = entries->slot4();
    int threshold = arg0->module->fn_27_14A38();

    if (count > threshold) {
        for (int i = 0; i < count; ++i) {
            if (entries->slot3(i) >= threshold) {
                Target* target = entries->slot2(i)->target;
                if ((((unsigned int)target->flag >> 7) & 1U) && target->state != 1) {
                    target->slot1(arg1);
                }
            }
        }
    }

    arg0->module->fn_27_14134(arg1);
}
