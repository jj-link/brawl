#pragma force_active on

class A {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class B {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(float f);
};

class gfSceneRoot {
public:
    void setCurrentFrame(float f);
    char pad[0x54];
    A* m_a;
};

void gfSceneRoot::setCurrentFrame(float f) {
    if (m_a != 0) {
        m_a->f5();
        char* p = (char*)this;
        int i = 0;
        do {
            B* b = *(B**)(p + 0x394);
            if (b != 0) {
                b->f5(f);
            }
            i++;
            p += 0x18;
        } while (i < 9);
    }
}
