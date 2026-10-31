#pragma force_active on
struct fnDispatchTarget {
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(int arg);
    char pad[0x24];
    int m_28;
};

extern "C" {
void fn_27_1500F4(fnDispatchTarget* self, int p2) {
    if (self->m_28 >= 0) {
        if (p2 == 0) return;
        if (p2 == 1) return;
        if (p2 == 0x24) return;
        if (p2 == 0x27) return;
        if (p2 == 0x2c) return;
    }
    self->vf6(p2);
}
}
