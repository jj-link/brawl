#pragma force_active on
struct fn_27_Pair {
    float x0;
    float y0;
    float z0;
    float x1;
    float y1;
    float z1;
};

struct fn_27_Helper {
    virtual void v0();
    virtual fn_27_Pair* getAt(int index);
    virtual void v2();
    virtual int getCount();
};

struct fn_27_Obj {
    char pad[0x5c];
    fn_27_Helper* m_helper;
};

extern "C" {
void fn_27_23C2C(fn_27_Obj* self) {
    int count = self->m_helper->getCount();
    for (int i = 0; i < count; i++) {
        fn_27_Pair* p = self->m_helper->getAt(i);
        p->x1 = p->x0;
        p->y1 = p->y0;
        p->z1 = p->z0;
    }
}
}
