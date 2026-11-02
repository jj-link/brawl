#pragma force_active on

struct Component {
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
    virtual int ready();
};

struct Entry {
    char pad[0x88];
    Component c;
};

static inline bool allReady(char* self, int offset) {
    for (int i = 0; i < 1; ++i) {
        char* e;
        if (i == 0)
            e = self + offset;
        else
            e = 0;
        if (reinterpret_cast<Entry*>(e)->c.ready() == 0)
            return false;
    }
    return true;
}

extern "C" bool fn_27_384978(char* self, unsigned int unused, unsigned int kind) {
    switch (kind) {
    case 0: return !allReady(self, 0x2094);
    case 1: return !allReady(self, 0x18);
    case 2: return false;
    case 3: return false;
    case 4: return false;
    case 5: return false;
    case 6: return false;
    case 7: return false;
    case 8: return false;
    case 9: return false;
    case 10: return false;
    case 11: return false;
    case 12: return false;
    case 13: return false;
    case 14: return false;
    case 15: return false;
    case 16: return false;
    default: return false;
    }
}
