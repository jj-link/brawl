#include <wn/wn_em_simple.h>
#pragma force_active on

#pragma inline_depth(1)
#pragma section const_type ".rodata" ".rodata"

namespace Matching {

struct Event {
    int kind;
    bool flag;
    u32 id;
};

class soAnimCmdEventObserver {
public:
    virtual void addObserver();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void fn_41_12100();
    virtual void fn_41_13608();
    virtual void fn_41_13600();
    virtual void fn_41_135BC();
    virtual void fn_41_12784();
    virtual void fn_41_135B0();
    virtual void fn_41_135A4();
    virtual void fn_41_135A0();
    virtual void fn_41_12D6C();
    virtual void fn_41_12DC4();
    virtual void fn_41_12800(int, Event*);
};

class soNullable {
public:
    virtual void isNull();
    virtual int* slot1(int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
};

struct Modules {
    char pad[0x54];
    soAnimCmdEventObserver* link;
};

struct Access {
    char pad[0xD8];
    Modules* modules;
};

struct Enemy {
    char pad[0x21CC];
    u32 id;
    u32 unk;
    float hp;
    float maxHp;
    char pad2[0x2214 - 0x21DC];
    bool enter;
    bool flag15;
    bool flag16;
    bool flag17;
    char pad3[0x2234 - 0x2218];
    u32* params;
    soNullable array;
};

}

extern "C" void fn_41_45A28(Matching::Enemy* a, Matching::Access* b) {
    using namespace Matching;

    struct {
        Event e3, e2, e1;
    } stack;

    bool entered = a->enter;
    a->enter = false;
    if (entered)
        ((wnemSimple*)a)->setProcFnc_HpZero(17);

    if (a->flag16) {
        ((wnemSimple*)a)->executeAnimCmd((u32)0);
        ((wnemSimple*)a)->executeAnimCmd((u32)1);

        u32 id = a->id;
        stack.e1.kind = 1;
        stack.e1.flag = false;
        stack.e1.id = id;

        Matching::soAnimCmdEventObserver* l = b->modules->link;
        l->fn_41_12800(3, &stack.e1);

        a->flag16 = false;
        a->flag17 = false;
    } else {
        if (a->flag17)
            a->flag17 = false;

        u32* p = 0;
        if (a->params)
            p = a->params;

        int state = *a->array.slot1(0);

        double dead = 1.0f + (-1.0f * a->hp);
        float hp = a->maxHp;
        if (hp <= 0.0f)
            hp = 1.0f;

        float ratio = 100.0f * (a->hp / hp);

        if (state == 0) {
            if (ratio <= (float)p[2]) {
                u32 id = a->id;
                stack.e2.kind = 0x1400;
                stack.e2.flag = false;
                stack.e2.id = id;

                Matching::soAnimCmdEventObserver* l = b->modules->link;
                l->fn_41_12800(3, &stack.e2);
            }
        } else if (state == 1) {
            if (ratio <= (float)p[3]) {
                u32 id = a->id;
                stack.e3.kind = 0x1401;
                stack.e3.flag = false;
                stack.e3.id = id;

                Matching::soAnimCmdEventObserver* l = b->modules->link;
                l->fn_41_12800(3, &stack.e3);
            }
        }
    }
}
