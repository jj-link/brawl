#pragma force_active on
struct Obj {
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
    virtual void v15(int, void*);
};

extern "C" {
void fn_110_18780(void* unused, char* p);
}

extern "C" void fn_110_18780(void* unused, char* p) {
    struct Msg {
        unsigned int id;
        unsigned char flag;
    } msg;
    Obj* obj;

    obj = *(Obj**)((char*)*(char**)(p + 0xd8) + 0x54);
    msg.id = 0x83b;
    msg.flag = 0;
    obj->v15(3, &msg);
}
