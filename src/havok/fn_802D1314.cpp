#pragma force_active on

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

extern "C" void fn_802D1314(void* arg0, void* arg1) {
    Target* target = *(Target**)((char*)arg0 + 0x14);
    target->v8();
    *(unsigned char*)((char*)arg1 + 0x4) = 1;
}
