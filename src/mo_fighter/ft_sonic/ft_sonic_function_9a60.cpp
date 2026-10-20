#pragma force_active on
extern const float lbl_123_rodata_18;

struct VObj {
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
    virtual void setVal(unsigned int id, int val);
};

extern "C" {
void fn_123_9A60(char* self, int* msg) {
    if (msg[0] == 0x41) {
        int v = (int)(*(float*)&msg[1] * lbl_123_rodata_18);
        char* p = *(char**)(self + 0x60);
        p = *(char**)(p + 0xd8);
        p = *(char**)(p + 0xc8);
        ((VObj*)p)->setVal(0x117, v);
    }
}
}
