#pragma force_active on
#include <types.h>

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
    virtual void e6();
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
    virtual s32 e22();
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

class Obj {
public:
    virtual void o0();
    virtual void o1();
    virtual void o2();
    virtual void o3();
    virtual void o4();
    virtual void o5();
    virtual void o6();
};

struct Owner {
    void* vt;
    char pad[0x28];
    ElemList* m2c;
    Obj* m30;
    EvList* m34;
    Obj* m38;

    inline void run(u32 mode) {
        if (mode == 1U) {
            s32 j;
            Elem* b;
            s16 y;
            s32 i;
            Elem* a;
            for (i = m2c->size() - 1; i >= 0; i--) {
                a = *m2c->at(i);
                b = *m2c->at(i);
                s32 n = m34->size();
                for (j = 0; j < n; j++) {
                    s16 x = b->e7();
                    Ev* ev = m34->at(j);
                    if (x != -1) {
                        y = ev->m4;
                        if (x == y) {
                            if (getInstance__13soEventSystemFv()->v6(y) == 1U) {
                                getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), ev->m4)->v3(ev->m6, ev->m8);
                            }
                            ev->m8 = -1;
                            ev->m4 = -1;
                        }
                    }
                }
                m2c->remove(i);
                b->e26(1);
                a->e5();
            }
            m2c->l8();
            m30->o6();
            if (m38 != 0) {
                m38->o6();
            }
        } else {
            for (s32 i = m2c->size() - 1; i >= 0; i--) {
                if (*m2c->at(i) != 0) {
                    switch ((*m2c->at(i))->e22()) {
                    case 0: {
                        Elem* a;
                        s32 j;
                        Elem* b;
                        s16 y;
                        a = *m2c->at(i);
                        b = *m2c->at(i);
                        s32 n = m34->size();
                        for (j = 0; j < n; j++) {
                            s16 x = b->e7();
                            Ev* ev = m34->at(j);
                            if (x != -1) {
                                y = ev->m4;
                                if (x == y) {
                                    if (getInstance__13soEventSystemFv()->v6(y) == 1U) {
                                        getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), ev->m4)->v3(ev->m6, ev->m8);
                                    }
                                    ev->m8 = -1;
                                    ev->m4 = -1;
                                }
                            }
                        }
                        m2c->remove(i);
                        b->e26(1);
                        a->e5();
                        break;
                    }
                    case 1: {
                        s16 y;
                        s32 j;
                        Elem* b;
                        b = *m2c->at(i);
                        s32 n = m34->size();
                        for (j = 0; j < n; j++) {
                            s16 x = b->e7();
                            Ev* ev = m34->at(j);
                            if (x != -1) {
                                y = ev->m4;
                                if (x == y) {
                                    if (getInstance__13soEventSystemFv()->v6(y) == 1U) {
                                        getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), ev->m4)->v3(ev->m6, ev->m8);
                                    }
                                    ev->m8 = -1;
                                    ev->m4 = -1;
                                }
                            }
                        }
                        m2c->remove(i);
                        b->e26(1);
                        break;
                    }
                    case 2:
                        break;
                    }
                }
            }
        }
    }
};

extern "C" void fn_27_932A0(Owner* self, u32 mode) {
    self->run(mode);
}
