#pragma force_active on
struct Msg {
    int type;
    float value;
};

extern float lbl_105_rodata_2C;

struct Target {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v7(int a, unsigned int b);
};

extern "C" {
void fn_105_CC10(unsigned char* self, Msg* msg) {
    if (msg->type == 0x3C) {
        int v = (int)(msg->value * lbl_105_rodata_2C);
        Target* c = *(Target**)(*(unsigned char**)(*(unsigned char**)(self + 0x60) + 0xD8) + 0x64);
        c->v7(v, 0x10000041);
    }
}
}
