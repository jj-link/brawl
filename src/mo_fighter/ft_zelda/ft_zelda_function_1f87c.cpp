#pragma force_active on
class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int, void*);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(unsigned int);
    virtual void v18();
    virtual void v19(unsigned int);
};

class SubObj {
public:
    char pad[0x64];
    VObj* a;
    char pad2[0x08];
    VObj* b;
};

extern "C" {
void fn_104_1F87C(void* unused, char* p) {
    SubObj* sub = *(SubObj**)(p + 0xD8);
    VObj* o1 = sub->a;
    VObj* o2 = sub->b;
    if (o1->v17(0x22000012)) {
        o1->v19(0x22000012);
        o2->v3(0x11d, p);
    }
}
}
