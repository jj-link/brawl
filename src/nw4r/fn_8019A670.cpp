#pragma force_active on
struct Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14(int);
    int m_4;
    int m_8;
    int m_c;
    int m_10;
    int m_14;
    int m_18;
    unsigned* m_1c;
};

extern "C" void fn_8019A670(Obj* self, int type, int unused, unsigned val) {
    switch (type) {
    case 0x10001: {
        int count = self->m_18;
        for (int i = 0; i < count; i++) {
            unsigned v = self->m_1c[i];
            if (v == val) {
                return self->vf14(i);
            }
        }
        break;
    }
    case 0x10003:
        self->m_4 = 0;
        break;
    case 0x10002:
        self->m_4 = val;
        break;
    }
}
