#pragma force_active on
typedef unsigned char u8;
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void processDefault();
    virtual void fn_27_2411DC();
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
    virtual void fn_27_241184();
    virtual void fn_27_2412EC();
    virtual void fn_27_241378();
    unsigned int pad40;
    u8 state;
    u8 pad45;
    u8 enabled;
    u8 flag;
};
extern "C" {
extern void* lbl_805A0350;
void fn_8010F4AC(void*, int);
int fn_8010F624(void*);
void fn_8010F754(void*);
void fn_27_2411DC(gfTask* self) {
    if (self->enabled != 0) {
        switch ((int)self->state) {
        case 0:
            if (self->flag != 1)
                self->state = 1;
            break;
        case 1:
            fn_8010F4AC(lbl_805A0350, 1);
            self->state = 2;
            break;
        case 2:
            if (fn_8010F624(lbl_805A0350) != 0)
                self->state = 3;
            break;
        case 3:
            if (self->flag == 1)
                self->state = 5;
            break;
        case 5:
            self->fn_27_241378();
            fn_8010F754(lbl_805A0350);
            if (self->flag == 1)
                self->state = 6;
            else
                self->state = 0;
            break;
        }
    }
}
}