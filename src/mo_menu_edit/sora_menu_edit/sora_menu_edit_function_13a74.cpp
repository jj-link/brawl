#include <mu/mu_object.h>
#include <mt/mt_prng.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_5_data_E24[];
extern char lbl_5_data_E28[];
}

struct Global {
    char pad[0x19c];
    int counts[24];

    int getCount(unsigned int index) {
        return index >= 24 ? 0 : counts[index];
    }
};

extern Global* lbl_805A01D8;

struct Data {
    char pad0[0x16c];
    MuObject* object;
    char pad170[0x28];
    int value;
    char pad19c[0x1bfc - 0x19c];
    int state;
    char pad1c00[0x150];
    int a;
    char pad1d54[4];
    int b;
    int c;
    unsigned int d;
    unsigned int e;

    inline void selectRandom() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;

        Global* g = lbl_805A01D8;
        int count = 0;
        for (unsigned int i = 0; i < 21; ++i) {
            if (g->getCount(i) != 0)
                ++count;
        }

        d = randi(count);
        e = randi(g->getCount(d));
    }
};

struct Base {
    char pad[0x3c];
};

struct Menu : Base {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void fB0(int);
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f1CC();
    virtual void f1D0(int, int);

    char pad40[0x16c];
    Data* data;
};

struct Name {
    char s[65];
};

extern "C" void fn_5_13A74(Menu* self) {
    self->data->selectRandom();

    self->f1CC();
    self->f1D0(0, 0);

    MuObject* obj = self->data->object;
    char* mdl = *(char**)((char*)obj + 8);
    int offset = *(int*)(mdl + 0x3c);
    const char* name = offset ? mdl + offset : 0;

    Name n;
    n.s[0] = 0;
    strcat(n.s, name);
    Name n2 = n;
    strcat(n2.s, lbl_5_data_E28);
    Name n3 = n2;
    sprintf(n3.s + strlen(n3.s), lbl_5_data_E24, 0);
    Name n4 = n3;
    obj->changeNodeAnimNIf(n4.s);

    self->fB0(self->data->value);
    self->data->state = 0x1c;
}
