#include <snd/snd_system.h>
#pragma force_active on

extern "C" int fn_80073D08(sndSystem*, unsigned int);
extern "C" void* lbl_27_bss_5668;

struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual unsigned int slot27();
    unsigned int pad40;
    unsigned char state;
    unsigned char pad45;
    unsigned char enabled;
    unsigned char flag;
    int handle;
    unsigned int id;
    int heap;
};

extern "C" void fn_27_2414E0(gfTask* self) {
    if (self->enabled != 0) {
        switch ((int)self->state) {
        case 0:
            if (self->flag == 1) {
                self->state = 6;
            }
            self->id = self->slot27();
            if (self->id != 0xffffffff) {
                self->state = 1;
            }
            break;
        case 1:
            self->handle = g_sndSystem->loadSoundGroup((SndGroupID)self->id, self->heap, true);
            self->state = 2;
            break;
        case 2:
            if (fn_80073D08(g_sndSystem, self->id) != 0) {
                self->state = 3;
            }
            break;
        case 3:
            if (lbl_27_bss_5668 != 0) {
                *(int*)((char*)lbl_27_bss_5668 + 0xb8) = self->handle;
            }
            if (self->flag == 1 || self->id != self->slot27()) {
                self->state = 5;
            }
            break;
        case 5:
            g_sndSystem->freeGroup(self->handle, self->heap);
            self->handle = -1;
            if (self->flag == 1) {
                self->state = 6;
            } else {
                self->state = 0;
            }
            break;
        }
    }
}