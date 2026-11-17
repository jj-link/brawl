#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
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
};

struct A {
    char pad[0x7c];
    Object_vptr_0* m_iface;
};

struct Obj {
    char pad[0xd8];
    A* m_a;
};

extern "C" void fn_27_1DCC10(int idx, int arg2, Obj* obj) {
    if (idx <= -1 || idx >= 2) {
        return;
    }
    switch (idx) {
    case 0:
        obj->m_a->m_iface->slot12();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 4: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    case 12: return;
    case 13: return;
    case 14: return;
    case 15: return;
    case 16: return;
    case 17: return;
    case 18: return;
    case 19: return;
    case 20: return;
    case 21: return;
    case 22: return;
    case 23: return;
    case 24: return;
    case 25: return;
    case 26: return;
    case 27: return;
    case 28: return;
    case 29: return;
    case 30: return;
    case 31: return;
    }
}
