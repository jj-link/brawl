#pragma force_active on
class soSubAbstract {
public:
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
    virtual ~soSubAbstract();
};

class soOuter {
public:
    virtual void vo0();
    void* m_pad[3];
    soSubAbstract m_sub;
};

extern "C" {
void fn_27_264114(soOuter* p) {
    p->m_sub.vf8();
}
}
