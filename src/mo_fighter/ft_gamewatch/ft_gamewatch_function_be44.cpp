#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Msg {
    s32 type;
    float value;
};

extern const float lbl_107_rodata_34;

struct Target {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void call(s32 a, u32 b);
};

extern "C" {
void fn_107_BE44(void* self, Msg* msg);
}

void fn_107_BE44(void* self, Msg* msg) {
    if (msg->type == 0x3d) {
        s32 v = (s32)(msg->value * lbl_107_rodata_34);
        u8* a = *(u8**)((u8*)self + 0x60);
        u8* b = *(u8**)(a + 0xd8);
        Target* c = *(Target**)(b + 0x64);
        c->call(v, 0x10000046);
    }
}
