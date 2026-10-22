#pragma force_active on

class Handler {
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
    virtual void onEvent(void*, void*);

    char pad[0xE0];
    void* target;
};

extern "C" {
extern void* lbl_805A033C;
extern void* lbl_805A0344;

void fn_8010C004(Handler* handler) {
    handler->onEvent(handler->target, lbl_805A033C);
    handler->onEvent(handler->target, lbl_805A0344);
}
}
