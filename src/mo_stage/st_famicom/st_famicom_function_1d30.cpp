#pragma force_active on
#include <st/st_trigger_observe.h>

typedef unsigned char u8;
typedef unsigned long u32;

extern "C" {
void setAreaSleep__9stTriggerFb(void* trigger, bool sleep);
void fn_27_233BE4(void* trigger, grGimmickWindData2nd* wnd);
}

struct Ent {
    char pad0[0x2EC];
    Vec2f pos;
    char pad1[4];
    u32 f2F8;
    u8 f2FC;
};

struct Owner {
    char pad0[0x378];
    void* trig[4];
    grGimmickWindData2nd* wnd[4];
};

extern "C" void fn_68_1D30(Owner* self) {
    Ent* e;
    Owner* p;
    u32 i;
    u8 n;
    setAreaSleep__9stTriggerFb(self->trig[0], true);
    setAreaSleep__9stTriggerFb(self->trig[1], true);
    setAreaSleep__9stTriggerFb(self->trig[2], true);
    setAreaSleep__9stTriggerFb(self->trig[3], true);
    n = 0;
    i = 0;
    for (;;) {
        e = (Ent*)((char*)self + (u8)i * 0x14);
        if (e->f2FC == 0) {
            p = (Owner*)((char*)self + n * 4);
            *(u32*)&p->wnd[0]->m_60 = e->f2F8;
            p->wnd[0]->m_areaData.m_offsetPos = e->pos;
            fn_27_233BE4(p->trig[0], p->wnd[0]);
            setAreaSleep__9stTriggerFb(p->trig[0], false);
            e->f2FC = 0xD;
            n++;
        }
        if (n == 4) {
            break;
        }
        i++;
        if (i == 7) {
            break;
        }
    }
}
