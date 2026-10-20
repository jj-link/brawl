#pragma force_active on
struct Pad {
    int a;
    int b;
};

class VOuter : public Pad {
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
};

class VBase {
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
    virtual void v11();
};

extern "C" void fn_27_190C58(void* unused, char* p) {
    char* q = *(char**)(p + 0xd8);
    VBase* o1 = *(VBase**)(q + 0x7c);
    o1->v9();

    char* r = *(char**)(p + 0xd8);
    VOuter* o2 = *(VOuter**)(r + 0x9c);
    o2->v6();
}
