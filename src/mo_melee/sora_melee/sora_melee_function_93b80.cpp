#pragma force_active on
typedef signed short s16;
typedef signed int s32;
typedef unsigned int u32;

class Mgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(s16 a, s16 b);
};

class soEventSystem {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual u32 v6(s16 id);
};

extern "C" soEventSystem* getInstance__13soEventSystemFv();
extern "C" Mgr* getManager__13soEventSystemFl(soEventSystem*, s32);

struct Ev {
    s16 m0;
    s16 m2;
    s16 m4;
    s16 m6;
    s16 m8;
};

class Elem {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual s32 getId();
    virtual s16 e7();
    virtual void e8();
    virtual void e9();
    virtual void e10();
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual void e19();
    virtual void e20();
    virtual void e21();
    virtual void e22();
    virtual void e23();
    virtual void e24();
    virtual void e25();
    virtual void e26(s32 a);
};

class ElemList {
public:
    virtual void l0();
    virtual Elem** at(s32 i);
    virtual void l2();
    virtual s32 size();
    virtual void l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
    virtual void l8();
    virtual void l9();
    virtual void l10();
    virtual void l11();
    virtual void remove(s32 i);
};

class EvList {
public:
    virtual void l0();
    virtual Ev* at(s32 i);
    virtual void l2();
    virtual s32 size();
};

class Owner {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
    virtual void o7();
    virtual void o8();
    virtual void o9();
    virtual void o10();
    virtual void o11();
    virtual void o12();
    virtual void o13();
    virtual void o14();
    virtual void o15();
    virtual void o16();
    virtual void o17();
    virtual s32 isValid();
    char pad[0x28];
    ElemList* m2c;
    int pad2;
    EvList* m34;
};

extern "C" void fn_27_93B80(Owner* self, s32 id, s32 mode) {
    if (self->isValid()) {
        switch (mode) {
        case 1: {
            s32 j;
            Elem* b;
            s16 y;
            s32 i;
            Elem* a;
            for (i = 0; i < self->m2c->size(); i++) {
                if (*self->m2c->at(i) && id == (*self->m2c->at(i))->getId()) {
                    a = *self->m2c->at(i);
                    b = *self->m2c->at(i);
                    s32 n = self->m34->size();
                    for (j = 0; j < n; j++) {
                        s16 x = b->e7();
                        Ev* ev = self->m34->at(j);
                        if (x != -1) {
                            y = ev->m4;
                            if (x == y) {
                                if (getInstance__13soEventSystemFv()->v6(y) == 1) {
                                    getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), ev->m4)->v3(ev->m6, ev->m8);
                                }
                                ev->m8 = -1;
                                ev->m4 = -1;
                            }
                        }
                    }
                    self->m2c->remove(i);
                    b->e26(1);
                    a->e5();
                    return;
                }
            }
            break;
        }
        case 0:
        case 2: {
            for (s32 i = self->m2c->size() - 1; i >= 0; i--) {
                if (*self->m2c->at(i) && id == (*self->m2c->at(i))->getId()) {
                    Elem* a = *self->m2c->at(i);
                    s16 y;
                    s32 j;
                    Elem* b = *self->m2c->at(i);
                    s32 n = self->m34->size();
                    for (j = 0; j < n; j++) {
                        s16 x = b->e7();
                        Ev* ev = self->m34->at(j);
                        if (x != -1) {
                            y = ev->m4;
                            if (x == y) {
                                if (getInstance__13soEventSystemFv()->v6(y) == 1) {
                                    getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), ev->m4)->v3(ev->m6, ev->m8);
                                }
                                ev->m8 = -1;
                                ev->m4 = -1;
                            }
                        }
                    }
                    self->m2c->remove(i);
                    b->e26(1);
                    a->e5();
                    if (mode == 2) {
                        break;
                    }
                }
            }
            break;
        }
        }
    }
}
