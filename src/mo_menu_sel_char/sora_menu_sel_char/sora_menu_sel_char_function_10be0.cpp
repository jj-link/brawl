#pragma force_active on
class VB {
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
    virtual void v11(void* a, void* b);
    virtual void v12();
    virtual void v13(void* a);
};

extern "C" {
void printIndex__5MuMsgFUlUlPv(void* msg, unsigned long a, unsigned long b, void* c);
void setFrameNode__8MuObjectFf(void* obj, float frame);
void playSE__9sndSystemF5SndIDiiii(void* snd, int id, int a, int b, int c, int d);
extern void* g_sndSystem;
extern float lbl_10_rodata_2F0;
extern float lbl_10_rodata_450;

void fn_10_10BE0(char* self, unsigned long arg1) {
    char* r31 = *(char**)(self + 0x428);
    printIndex__5MuMsgFUlUlPv(*(void**)(self + 0x5c4), 7, arg1, 0);
    VB* p = *(VB**)(self + 0x6c);
    p->v13(*(void**)(r31 + 0x10));
    p = *(VB**)(self + 0x6c);
    p->v11(*(void**)((char*)p + 0xe4), *(void**)(r31 + 0x10));
    setFrameNode__8MuObjectFf(r31, lbl_10_rodata_2F0);
    char* r4 = *(char**)(r31 + 0x14);
    VB* q = *(VB**)(r4 + 0xc);
    q->v8(lbl_10_rodata_450);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 0x1EF3, -1, 0, 0, -1);
}
}
