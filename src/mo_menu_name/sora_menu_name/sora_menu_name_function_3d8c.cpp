#pragma force_active on

extern "C" {
void setFrameNode__8MuObjectFf(void* obj, float frame);
void fn_801B4CB0(void*, void*, int);
void fn_16_5A8(void* self, const char* name, int a, int c);
void playSE__9sndSystemF5SndIDiiii(void* snd, int id, int a, int b, int c, int d);
extern void* g_sndSystem;
extern const float lbl_16_rodata_60[];
}

class VirtBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(float f);
    virtual void v9();
    virtual void v10();
    virtual void v11(int, int);
};

struct Holder {
    char pad0[0x14];
    VirtBase* unk14;
};

extern "C" void fn_16_3D8C(char* self) {
    const float* ro = lbl_16_rodata_60;
    if (*(int*)(self + 0x98) != 2) {
        Holder* obj = *(Holder**)(self + 0x40);
        setFrameNode__8MuObjectFf(obj, ro[0x1b4 / 4]);
        VirtBase* sub = *(VirtBase**)((char*)obj->unk14 + 0xc);
        sub->v8(ro[0xc8 / 4]);
    }
    if (*(void**)(self + 0x3f8) != 0) {
        fn_801B4CB0(*(void**)(self + 0x3f8), *(void**)(self + 0x90), *(int*)(self + 0x3fc));
    } else {
        VirtBase* a = *(VirtBase**)(self + 0xa8);
        a->v11(*(int*)((char*)a + 0xe4), *(int*)(self + 0x90));
    }
    Holder* obj2 = *(Holder**)(self + 0x48);
    setFrameNode__8MuObjectFf(obj2, ro[0x120 / 4]);
    VirtBase* sub2 = *(VirtBase**)((char*)obj2->unk14 + 0xc);
    sub2->v8(ro[0xc8 / 4]);
    *(int*)(self + 0x1e8) = *(int*)(self + 0x3e0);
    fn_16_5A8(self + 0x158, 0, 0, 5);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 5, -1, 0, 0, -1);
}
