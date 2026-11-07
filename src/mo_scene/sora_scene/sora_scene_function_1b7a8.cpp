#pragma force_active on
typedef unsigned char u8;
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void fn_1_8AE0();
    virtual void processAnim();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_1_8B3C();
    virtual void fn_1_8ADC(void*);
};

struct S3 { u8 a, b, c; };
struct S90 { long long d[0x12]; };
struct S284 { int d[0xA1]; };
struct GData { S3 h; S90 s1; S284 s2; };
struct GGlobal { char pad[8]; GData* data; };
struct Loader { char pad[0x57]; u8 f57; u8 f58; char pad2[4]; u8 b7 : 1; u8 rest : 7; };
struct Obj6C { char pad[0x50]; void* p; };
struct LdrMgr { void* p[14]; };
struct Self {
    char pad[8];
    Loader* ldr[7];
    void* l24; void* l28; void* l2c; void* l30; void* l34; void* l38; void* l3c;
    void* p40; void* p44; void* p48; char pad4c[0x8]; gfTask* p54; char pad58[8];
    void* p60; char pad64[4]; void* p68; Obj6C* p6c[7];
    char pad88[0xD1 - 0x88]; u8 fd1; char padd2[6]; u8 fd8;
};
struct CameraController { enum Kind {}; static CameraController* getInstance(); void changeInput(Kind); };
struct cmAI { char pad[0x94]; u8 f94; };

extern "C" {
void GXSetMisc(int, int);
void fn_1_139E0(void*);
void fn_1_1A4DC(void*);
void fn_8004E858(GGlobal*);
void fn_80016900(void*, unsigned int, unsigned int);
void fn_27_109148(void*, int);
void fn_27_23BB10(Loader*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
Obj6C* fn_27_2454E0(void*);
void fn_27_1F1844(int);
void* fn_27_241F50(void*);
void* fn_27_244240(void*);
void* fn_27_246E74(void*, int);
void fn_27_241E30(void*, void*);
gfTask* fn_27_24F644(void*);
extern GGlobal* g_GameGlobal;
extern void* g_gfApplication;
extern LdrMgr* g_stLoaderManager;
extern void* g_ftManager;
extern cmAI* g_cmAIController;
extern GData lbl_1_bss_90;
extern char lbl_1_data_1F88[];
extern char lbl_1_data_1E00[];
}

static inline void cp7(void** d, Self* s) {
    d[0] = s->ldr[0]; d[1] = s->ldr[1]; d[2] = s->ldr[2]; d[3] = s->ldr[3];
    d[4] = s->ldr[4]; d[5] = s->ldr[5]; d[6] = s->ldr[6];
}

static inline void* makeQ() {
    char* q = (char*)__nw__FUlQ25Heaps8HeapType(0x48, 2);
    if (q) {
        fn_27_241E30(q, lbl_1_data_1F88);
        *(void**)(q + 0x3c) = lbl_1_data_1E00;
    }
    return q;
}

extern "C" void fn_1_1B7A8(Self* self) {
    GXSetMisc(1, 8);
    fn_1_139E0(self);
    lbl_1_bss_90 = *g_GameGlobal->data;
    fn_8004E858(g_GameGlobal);
    fn_80016900(g_gfApplication, 0, 0);
    fn_1_1A4DC(self);
    self->fd1 = 0;
    self->ldr[0] = (Loader*)g_stLoaderManager->p[0];
    self->ldr[1] = (Loader*)g_stLoaderManager->p[1];
    self->ldr[2] = (Loader*)g_stLoaderManager->p[2];
    self->ldr[3] = (Loader*)g_stLoaderManager->p[3];
    self->ldr[4] = (Loader*)g_stLoaderManager->p[4];
    self->ldr[5] = (Loader*)g_stLoaderManager->p[5];
    self->ldr[6] = (Loader*)g_stLoaderManager->p[6];
    self->l24 = g_stLoaderManager->p[7];
    self->l34 = g_stLoaderManager->p[8];
    self->l2c = g_stLoaderManager->p[9];
    self->l30 = g_stLoaderManager->p[10];
    self->l28 = g_stLoaderManager->p[11];
    self->l38 = g_stLoaderManager->p[12];
    self->l3c = g_stLoaderManager->p[13];
    fn_27_109148(g_ftManager, 0);
    for (int i = 0; i < 7; i++) {
        if (self->ldr[i]) self->ldr[i]->f57 = 1;
        if (self->ldr[i]) self->ldr[i]->f58 = 0;
        if (self->ldr[i]) fn_27_23BB10(self->ldr[i]);
        if (self->ldr[i]) self->ldr[i]->b7 = 0;
        if (self->ldr[i]) {
            Obj6C* o = (Obj6C*)__nw__FUlQ25Heaps8HeapType(0x54, 2);
            if (o) o = fn_27_2454E0(o);
            self->p6c[i] = o;
            if (o) o->p = self->ldr[i];
        }
    }
    fn_27_1F1844(0);
    CameraController::getInstance()->changeInput((CameraController::Kind)2);
    g_cmAIController->f94 &= ~0x10;
    void* p = __nw__FUlQ25Heaps8HeapType(0x64, 2);
    if (p) p = fn_27_241F50(p);
    self->p40 = p;
    p = __nw__FUlQ25Heaps8HeapType(0x1B8, 2);
    if (p) p = fn_27_244240(p);
    self->p44 = p;
    p = __nw__FUlQ25Heaps8HeapType(0x104, 2);
    if (p) p = fn_27_246E74(p, 1);
    self->p48 = p;
    self->p60 = makeQ();
    gfTask* t = (gfTask*)__nw__FUlQ25Heaps8HeapType(0xCC, 2);
    if (t) t = fn_27_24F644(t);
    self->p54 = t;
    if (self->p68) cp7((void**)((char*)self->p68 + 0x48), self);
    if (self->p44) *(void**)((char*)self->p44 + 0x90) = self->p48;
    if (self->p44) cp7((void**)((char*)self->p44 + 0x74), self);
    if (self->p48) cp7((void**)((char*)self->p48 + 0x58), self);
    if (self->p48) *(void**)((char*)self->p48 + 0x74) = self->p40;
    if (self->p54) self->p54->fn_1_8ADC(self->p40);
    self->fd8 &= ~2;
}
