#pragma force_active on
class Vt {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11(int);
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34(int, unsigned int);
};

struct stC {
    Vt* m_0;
};

class stX : public Vt {
public:
    char pad_04[0x28];
    Vt* m_2c;
    char pad_30[0x78 - 0x30];
    stC* m_78;
};

extern "C" void fn_27_73D24(stX* self, unsigned int x) {
    self->m_78->m_0->v8();
    self->m_2c->v11(0);
    self->v34(-1, x);
}
