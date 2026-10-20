#pragma force_active on
extern "C" void fn_800765B0(void*, void*, int);

extern void* g_sndSystem;
extern const float lbl_27_rodata_728;

class VBase {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

struct SndObj {
    char pad0[0x34];
    void* field34;
    void* field38;
    VBase* field3c;
    char pad1[0x50 - 0x40];
    float field50;
    int field54;
};

extern "C" {
void fn_27_5680C(SndObj* self) {
    fn_800765B0(g_sndSystem, self->field34, 0);
    fn_800765B0(g_sndSystem, self->field38, 0);
    self->field50 = lbl_27_rodata_728;
    self->field3c->f2();
    self->field54 = -1;
}
}
