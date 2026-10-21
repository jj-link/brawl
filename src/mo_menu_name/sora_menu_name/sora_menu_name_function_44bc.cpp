#pragma force_active on
class MuObject;
class sndSystem;
typedef int SndID;

extern "C" {
void setFrameNode__8MuObjectFf(void* obj, float frame);
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
};

struct Holder {
    char pad0[0x14];
    VirtBase* unk14;
};

extern "C" void fn_16_44BC(char* self) {
    const float* ro = lbl_16_rodata_60;
    if (*(int*)(self + 0x98) != 2) {
        Holder* obj = *(Holder**)(self + 0x40);
        setFrameNode__8MuObjectFf(obj, ro[0x1c0 / 4]);
        VirtBase* sub = *(VirtBase**)((char*)obj->unk14 + 0xc);
        sub->v8(ro[0xc8 / 4]);
    }
    Holder* obj2 = *(Holder**)(self + 0x48);
    setFrameNode__8MuObjectFf(obj2, ro[0x1c4 / 4]);
    VirtBase* sub2 = *(VirtBase**)((char*)obj2->unk14 + 0xc);
    sub2->v8(ro[0xc8 / 4]);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 6, -1, 0, 0, -1);
}
