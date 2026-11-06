#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_ecMgr;
extern void* g_sndSystem;
int fn_80060858(void*, u32);
void* fn_800607C8(void*, u32);
float getFrame__16gfModelAnimationFd(void*);
void printIndex__5MuMsgFUlUlPv(void*, u32, u32, void*);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
}

struct Object {
    int state;
    u32 counter;
    int unk08;
    u32 effectHandle;
    void* message;
    u32 index;
    u32 unk18;
    u32 unk1c;
    u32 unk20;
    u32 pad24;
};

extern "C" void fn_27_2D5F04(Object* self) {
    int mgr = (int)g_ecMgr;
    void* model = 0;
    switch (self->state) {
    case 1: {
        if ((s32)self->unk1c >= 0) {
            u32 a, b;
            if (self->unk08 == 1) {
                a = 1;
                mgr = 2;
            } else {
                a = 2;
                mgr = 1;
            }
            char* c = (char*)self;
            printIndex__5MuMsgFUlUlPv(self->message, a + self->index, *(u32*)(c + a * 4 + 0x18), 0);
            printIndex__5MuMsgFUlUlPv(self->message, mgr + self->index, *(u32*)(c + mgr * 4 + 0x18), 0);
        }
        self->counter++;
        return;
    }
    case 2: {
        self->counter++;
        if (self->counter < 0x3C) {
            model = (void*)fn_80060858((void*)mgr, self->effectHandle);
            if (model != 0) {
                float f1 = getFrame__16gfModelAnimationFd(model);
                float f2 = getFrame__16gfModelAnimationFd(model);
                if (f2 < f1) return;
            }
        }
        model = fn_800607C8((void*)mgr, self->effectHandle);
        if (model != 0) {
            ((nw4r::g3d::ScnMdlSimple*)model)->SetScnObjOption(1, 1);
            ((nw4r::g3d::ScnMdlSimple*)model)->SetScnObjOption(6, 1);
            ((nw4r::g3d::ScnMdlSimple*)model)->SetScnObjOption(7, 1);
        }
        self->state = 0;
        playSE__9sndSystemF5SndIDiiii(g_sndSystem, 6, -1, 0, 0, -1);
        return;
    }
    }
}