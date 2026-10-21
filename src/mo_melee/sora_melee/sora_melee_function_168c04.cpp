#pragma force_active on
extern "C" {

class ObjA {
public:
    virtual int d0();
    virtual int d1();
    virtual int d2();
    virtual int d3();
    virtual int d4();
    virtual int d5();
    virtual int d6();
    virtual int d7();
    virtual int d8();
    virtual int d9();
    virtual int d10();
    virtual int d11();
    virtual int d12();
    virtual int d13();
    virtual int d14();
    virtual int d15();
    virtual int real();
};

class ObjB {
public:
    virtual int d0();
    virtual int d1();
    virtual int d2();
    virtual int d3();
    virtual int d4();
    virtual int real(int a, int b);
};

struct ContainerObj {
    void* m[25];
    ObjB* m_objB;
    void* pad1;
    void* pad2;
    ObjA* m_objA;
};

struct OuterObj {
    void* m[54];
    ContainerObj* m_container;
};

void fn_27_168C04(void* a, void* t) {
    OuterObj* self = (OuterObj*)t;
    self->m_container->m_objA->real();
    int r = self->m_container->m_objA->real();
    switch (r) {
    case 0x11:
        self->m_container->m_objB->real(-1, 0x20000000);
        break;
    }
}

}
