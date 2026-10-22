#pragma force_active on
extern "C" {

bool fn_801BD5E8(void* p);
void fn_801BD604(void* p);

}

class Obj {
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
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual int v21();
    virtual void v22();
};

extern "C" void fn_801CA720(void** arg0, void* arg1) {
    *arg0 = arg1;
    if (fn_801BD5E8(arg1)) {
        fn_801BD604(*arg0);
    }
    if (((Obj*)*arg0)->v21()) {
        ((Obj*)*arg0)->v22();
    }
    *(void***)((char*)*arg0 + 0xc) = arg0;
}
