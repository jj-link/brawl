#pragma force_active on
struct CaptainSubObj {
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
    virtual void v12(int, int);
};

extern "C" void fn_100_DC90(void*, char* self, int id) {
    if (id == 0x11a) {
        return;
    }
    if (id < 0x11a) {
        if (id == 0x3b) {
            return;
        }
    }
    CaptainSubObj* obj = *(CaptainSubObj**)(*(char**)(self + 0xd8) + 0x3c);
    obj->v12(0, id);
}
