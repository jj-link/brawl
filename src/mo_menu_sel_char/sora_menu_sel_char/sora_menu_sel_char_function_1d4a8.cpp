#include <types.h>
#pragma force_active on

struct SelSub {
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
    virtual void f13(void*);
};

struct SelElem {
    int pad[4];
    void* field10;
};

struct SelSelf {
    int state;
    int pad4[2];
    SelElem* elems[9];
    SelElem* edge[2];
    SelSub* obj38;
    SelSub* obj3C;
    int pad40[2];
    int n48;
    int pad4c[8];
    int n6C;
};

extern "C" void fn_10_1D4A8(void* self) {
    SelSelf* s = (SelSelf*)self;
    int max;
    int* p;
    int i;
    int idx = s->n48 - 4;
    switch (s->state) {
    case 0:
        max = s->n6C + 1;
        break;
    case 1:
        max = 9;
        break;
    case 2:
        max = 0x1F;
        break;
    case 3:
        max = 0x1F;
        break;
    }
    p = (int*)self;
    for (i = 0; i < 9; i++, p++, idx++) {
        SelElem* el;
        if (idx >= 0 && idx < max) {
            el = (SelElem*)p[3];
        } else if (s->state == 0 && (idx == -1 || idx == max)) {
            el = s->edge[((unsigned)((-1 - idx) | (idx + 1))) >> 31];
        } else {
            continue;
        }
        s->obj3C->f13(el->field10);
    }
    s->obj38->f13(s->obj3C);
}
