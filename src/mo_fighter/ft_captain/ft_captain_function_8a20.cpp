#pragma force_active on
extern "C" void fn_100_F3D0(void*);
extern "C" void fn_27_12DCA8(void*);

class VCall {
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
    virtual int v16();
};

extern "C" void fn_100_8A20(char* obj) {
    char* sub = *(char**)(obj + 0x60);
    char* a = *(char**)(sub + 0xD8);
    VCall* b = *(VCall**)(a + 0x70);
    int r = b->v16();
    if (r < 0x11D) {
        if (r == 0x116) {
            goto call;
        }
        goto done;
    }
    if (r >= 0x122) {
        goto done;
    }
call:
    fn_100_F3D0(sub);
done:
    fn_27_12DCA8(obj);
}
