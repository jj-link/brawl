#include <types.h>
#include <string.h>
#include <gf/gf_error_manager.h>
#include <ip/ip_switch.h>
#pragma force_active on

struct gfCameraController_base { char pad[4]; };
class gfCameraController : public gfCameraController_base {
public:
    virtual void slot0();
    u8 active;
};

struct Sub {
    u8 a, b;
    u32 c;
    u8 d, e;
    u16 f;
    u32 g, h, i;
};
struct Elem {
    u32 a;
    Elem* next;
    Elem* link;
    u8 b, c;
    u16 d;
    u32 e;
    Sub sub[4];
    char* buf;
};
struct Peer { s8 a; char pad[2]; s8 b; char rest[28]; };
struct Mgr {
    char pad0[0x14];
    u8 flag;
    char pad15[0xb];
    Elem* elems;
    char pad24[0x24];
    char* buf;
    char pad4c[0x5c];
    int state;
    char padac[4];
    Peer peers[4];
    char pad130[0x24];
    u32 size;
    char pad158[8];
    void* data;
    int stride;
    char pad168[0x2e8];
    u32 x450;
    Elem* list;
    Elem* freeList;
};
struct State {
    char pad0[0x60]; int x60; char pad64[0x10]; int x74; char pad78[0x10];
    int x88; char pad8c[0x10]; int x9c; char pada0[8];
    int state; char padac[0x94]; u16 port; char pad142[2]; u16 port2;
    char pad146[0x63]; u8 tick; char pad1aa[0xa]; u32 time;
    char pad1b8[6]; u16 code; char pad1c0[0x18];
    bool flag : 1;
    signed mode : 8;
    unsigned : 7;
    u8 reason;
    u8 pad1db;
    int timer, x1e0, x1e4, error;
};
extern Mgr* lbl_805A0390;
extern gfCameraController* lbl_805A0428;
extern int lbl_805A03E8;
extern u8 lbl_805A0409, lbl_8059E742;
extern char lbl_8045E018[], g_Network[];
extern void* g_muWifiInterfaceTask;
extern const float lbl_805A2B10;
extern void (*lbl_805A039C)(u16,u8);
extern void (*lbl_805A03A0)(u8,u16,u8);
extern "C" {
void netReport__FPCce(const char*, ...);
void fn_800C8F68(const char*, ...);
void fn_8013E470(State*, u16, int);
void fn_80140EBC(State*, int);
int fn_80141814(State*);
void fn_800D90CC(void*);
void fn_800CEDDC(void*);
void fn_801416CC(State*);
void fn_801424F8(State*);
int fn_80141474(State*, Elem*);
void fn_801419FC(State*);
void fn_80141EBC(State*);
void fn_8013E0B4(State*);
void fn_800D1A9C(void*);
void fn_8004A914(void*, int);
void fn_80146878(void*, int);
void fn_80142A80(State*);
void fn_8014044C(State*);
}
static inline void resetMgr(Mgr* g) {
    int i;
    Elem* e = g->elems;
    for (i = 0; i < 20; i++) {
        char* p = g->buf + g->stride * i;
        e->a = 0; e->next = 0; e->link = 0;
        e->b = 0; e->c = 0; e->d = 0;
        for (u8 j = 0; j < 4; j++) {
            e->sub[j].a = 0; e->sub[j].b = 0;
            e->sub[j].d = 0; e->sub[j].e = 0;
            e->sub[j].c = 0; e->sub[j].f = 0;
            e->sub[j].g = 0; e->sub[j].h = 0;
        }
        e->buf = p;
        e++;
    }
    g->x450 = 0; g->list = 0; g->flag = 0;
    g->freeList = g->elems;
    e = g->freeList;
    for (i = 0; i < 20; i++, e++) {
        if (i == 19) e->next = 0;
        else e->next = e + 1;
        e->link = 0;
    }
    memset(g->data, 0, g->size);
}
static inline void notifyCamera(int v) {
    if (lbl_805A0428) {
        lbl_805A0428->active = v;
        gfCameraController* p = lbl_805A0428;
        p->slot0();
        p = *(gfCameraController**)p;
        while (p) {
            p->slot0();
            p = *(gfCameraController**)p;
        }
    }
}
static inline void clearMgr() {
    fn_800D1A9C(g_muWifiInterfaceTask);
    lbl_805A0390->state = 0;
    resetMgr(lbl_805A0390);
    ipSwitch* s = ipSwitch::getInstance();
    if (*(int*)s == 1) {
        fn_8004A914(s, 0);
        notifyCamera(0);
    }
}
extern "C" void fn_80142EB0(State* self) {
    char* base = lbl_8045E018;
    if (gfErrorManager::getInstance()->m_isSuspended && self->error == 0) {
        self->error = 14;
        if (self->state == 6 && self->x1e0 == 0 && self->mode == 0) {
            self->flag = 1;
            self->timer = 80;
            self->mode = 2;
            self->reason = 100;
        }
        netReport__FPCce(base + 0x6e4);
    }
    if (lbl_805A03E8 == 0) {
        switch (self->state) {
        case 2:
            self->port2 = self->port + 1000;
            fn_8013E470(self, self->port2, 1);
            self->time = (u32)(lbl_805A2B10 * (float)((*(u32*)0x800000f8 / 4) / 1000));
            fn_80140EBC(self, 0);
            self->state = 3;
            break;
        case 3:
            if (fn_80141814(self)) self->state = 5;
            break;
        case 5: {
            fn_8013E470(self, self->port2, 0);
            notifyCamera(1);
            void* p = g_muWifiInterfaceTask;
            fn_800D90CC(p);
            fn_800CEDDC(p);
            netReport__FPCce(base + 0x710);
            self->state = 6;
            break;
        }
        case 6: {
            fn_801416CC(self);
            fn_801424F8(self);
            Elem* e = lbl_805A0390->list;
            while (e) {
                if (!fn_80141474(self, e)) break;
                e = e->link;
            }
            fn_801419FC(self);
            self->tick += lbl_805A0409;
            if (self->tick >= 60) {
                self->tick -= 60;
                fn_80141EBC(self);
            }
            fn_8013E0B4(self);
            if (self->mode >= 1 && self->timer != 0) {
                --self->timer;
                if (self->mode == 1) {
                    if (self->timer == 0) {
                        netReport__FPCce(base + 0x730, self->reason);
                        if (!self->flag) {
                            if (lbl_805A039C) lbl_805A039C(self->code, self->reason);
                            clearMgr();
                        } else {
                            netReport__FPCce(base + 0x74c);
                            goto disconnect;
                        }
                    }
                } else {
                    int count = 0;
                    for (unsigned i = 0; i < 4; i++) {
                        if (i != lbl_8059E742 && lbl_805A0390->peers[i].a && !lbl_805A0390->peers[i].b)
                            count++;
                    }
                    if (self->timer == 0 || count == 0) {
                    disconnect:
                        if (lbl_805A03A0) lbl_805A03A0(lbl_8059E742, self->code, self->reason);
                        clearMgr();
                        fn_80146878(g_Network, 0);
                        if (self->error) fn_800C8F68(base + 0x768, self->error);
                    }
                }
            }
            break;
        }
        }
        fn_80142A80(self);
        self->x60 = 0; self->x74 = 0; self->x88 = 0; self->x9c = 0;
        fn_8014044C(self);
    }
}
