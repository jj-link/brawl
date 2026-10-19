#pragma force_active on
extern "C" {
extern const float lbl_120_rodata_C;
}

class VObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(int v, unsigned int u);
};

struct Msg {
    int id;
    float value;
};

extern "C" void fn_120_90D4(void* self, Msg* msg) {
    if (msg->id == 0x3F) {
        int v = (int)(msg->value * lbl_120_rodata_C);
        void* obj = *(void**)((char*)self + 0x60);
        obj = *(void**)((char*)obj + 0xD8);
        obj = *(void**)((char*)obj + 0x64);
        ((VObj*)obj)->f5(v, 0x10000044);
    }
}
