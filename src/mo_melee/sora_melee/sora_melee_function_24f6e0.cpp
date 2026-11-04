#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
extern void* g_IfMngr;
void fn_800DE508(void* self, int arg1);
void fn_27_242418(void* self);
}

struct gfTask_base { char pad[0x3c]; };

class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void fn_27_24F6E0();
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
    virtual void fn_27_24F688();
    virtual void fn_27_248C88();
    virtual void fn_27_248C80();
    virtual void fn_27_248C78();
    virtual void fn_27_248C70();
    virtual void fn_27_24F7C0();
    virtual void fn_27_24F7D4();
    virtual void fn_27_24F81C();
    virtual void fn_27_24F7E0();
    virtual void fn_27_248C6C();
    virtual void fn_27_247EE8();
    virtual void fn_27_24F814();
    virtual void fn_27_24F810();
    virtual void fn_27_24F80C();
    virtual void fn_27_24F808();
    virtual void fn_27_24F804();
    virtual void fn_27_24F800();
    virtual void fn_27_248088();
    virtual void fn_27_248C68();
    virtual void fn_27_248C64();
    virtual u32 fn_27_24F7E8();

    u8 state40;
    u8 pad41;
    u8 flag42;
    u8 flag43;
    u32 pad44;
    void* ptr48;
};

extern "C" void fn_27_24F6E0(gfTask* self) {
    if (self->flag43 != 1 && self->flag42 != 1) {
        switch (self->state40) {
        case 1:
            if (self->fn_27_24F7E8() == 1U) {
                if (g_IfMngr != 0) {
                    fn_800DE508(*(void**)((char*)g_IfMngr + 0x44), 7);
                }
                if (self->ptr48 != 0) {
                    fn_27_242418(self->ptr48);
                }
                self->state40 = 2;
            }
            break;
        case 2:
            if (g_IfMngr != 0) {
                if (((int*)*(void**)((char*)g_IfMngr + 0x44))[1] == 0) {
                    self->state40 = 3;
                }
            } else {
                self->state40 = 3;
            }
            break;
        }
    }
}
