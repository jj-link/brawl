#pragma force_active on
struct DedVA {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int query(int);
};

struct DedVB {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void notify(int, int);
};

struct DedHolder {
    char pad[0x50];
    DedVB* m_b;
};

extern "C" void fn_117_10044(void*, void* accesser) {
    char* acc = (char*)accesser;
    DedHolder* holder = *(DedHolder**)(acc + 0xd8);
    DedVA* a = *(DedVA**)((char*)holder + 0x64);
    int result = a->query(0x20000005);
    if (result >= 0) {
        DedHolder* h2 = *(DedHolder**)(acc + 0xd8);
        h2->m_b->notify(result, 0);
    }
}
