#pragma force_active on
struct CaptainPad {
    int a;
    int b;
};

class CaptainObj : public CaptainPad {
public:
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
    virtual void v20();
    virtual void v21();
    virtual void action(void*, void*);
    virtual void v23();
    virtual unsigned int query();
};

extern "C" unsigned int fn_100_97F0(CaptainObj* self, void* a, void* b) {
    unsigned int result = self->query();
    if (result == 1) {
        self->action(a, b);
    }
    return result;
}
