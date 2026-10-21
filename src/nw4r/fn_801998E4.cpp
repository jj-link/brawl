#pragma force_active on
struct Obj {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(int type);
    int m_4;
};

extern "C" {
void fn_801998E4(Obj* self, int type, int unused, int val) {
    switch (type) {
    case 8:
        self->vf7(type);
        break;
    case 0x10003:
        self->m_4 = 0;
        break;
    case 0x10002:
        self->m_4 = val;
        break;
    }
}
}
