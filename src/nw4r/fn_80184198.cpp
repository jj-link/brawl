#pragma force_active on
class acObjB {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};

class acObjA {
public:
    char pad[0x10];
    acObjB* m_obj;
};

extern "C" void fn_80184198(acObjA* self) {
    acObjB* p = self->m_obj;
    if (p) {
        p->vf5();
    }
}
