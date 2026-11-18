#include <types.h>
#include <string.h>
#include <ip/ip_switch.h>

#pragma force_active on

class gfCameraController;

struct gfCameraController_base {
    gfCameraController* next;
};

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

struct Mgr {
    char pad0[0x14];
    u8 flag;
    char pad15[0xb];
    Elem* elems;
    char pad24[0x24];
    char* buf;
    char pad4c[0x5c];
    int state;
    char padac[0xa8];
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
    char pad0[0x4c];
    int x4c;
    int x50;
    int x54;
    char pad58[0x50];
    int state;
    char padac[0x94];
    u16 port;
    char pad142[2];
    u16 port2;
    char pad146[0x86];
    int x1cc;
};

struct PeerB {
    u8 a, b;
};

extern Mgr* lbl_805A0390;
extern gfCameraController* lbl_805A0428;
extern int lbl_805A03E8;
extern u8 lbl_8059E742;
extern PeerB lbl_805A0418[4];
extern char lbl_8045E018[];
extern void* g_muWifiInterfaceTask;
extern int g_NtMatchingStatus;

extern "C" {
void netReport__FPCce(const char*, ...);
void fn_800C8F68(const char*, ...);
void fn_800D1A9C(void*);
void fn_8004A914(void*, int);
int fn_800CB0D8(void*, int);
u8 fn_800CB194(void*, int);
void fn_80146F88(u8, u8);
int fn_8013FDD4(State*);
void fn_8014B130(int);
}

static inline void resetMgr(Mgr* g) {
    Elem* e = g->elems;
    int i;

    for (i = 0; i < 20; i++) {
        char* p = g->buf + g->stride * i;
        e->a = 0;
        e->next = 0;
        e->link = 0;
        e->b = 0;
        e->c = 0;
        e->d = 0;

        for (u8 j = 0; j < 4; j++) {
            e->sub[j].a = 0;
            e->sub[j].b = 0;
            e->sub[j].d = 0;
            e->sub[j].e = 0;
            e->sub[j].c = 0;
            e->sub[j].f = 0;
            e->sub[j].g = 0;
            e->sub[j].h = 0;
        }

        e->buf = p;
        e++;
    }

    g->x450 = 0;
    g->list = 0;
    g->flag = 0;
    g->freeList = g->elems;
    e = g->freeList;

    for (i = 0; i < 20; i++, e++) {
        if (i == 19)
            e->next = 0;
        else
            e->next = e + 1;
        e->link = 0;
    }

    memset(g->data, 0, g->size);
}

extern "C" int fn_8013F0B0(State* self) {
    u8 counts[4];
    char* base = lbl_8045E018;

    if (lbl_805A03E8 != 0) {
        fn_800D1A9C(g_muWifiInterfaceTask);
        lbl_805A0390->state = 0;
        resetMgr(lbl_805A0390);

        ipSwitch* s = ipSwitch::getInstance();
        if (*(int*)s == 1) {
            fn_8004A914(s, 0);
            if (lbl_805A0428) {
                lbl_805A0428->active = 0;
                gfCameraController_base* current;
                current = (gfCameraController_base*)lbl_805A0428;
                ((gfCameraController*)current)->slot0();
                gfCameraController* p = current->next;
                while (p) {
                    p->slot0();
                    p = p->next;
                }
            }
        }
        return 0;
    }

    memset(counts, 0, 4);
    for (int i = 0; i < 4; i++) {
        if (fn_800CB0D8(g_muWifiInterfaceTask, i) == 0)
            counts[fn_800CB194(g_muWifiInterfaceTask, i)]++;
    }

    int total = 0;
    for (u8 i = 0; i < 4; i++) {
        total += counts[i];
        fn_80146F88(i, counts[i]);
    }

    if (total == 0) {
        netReport__FPCce(base + 0x4c);
        for (u8 i = 0; i < 4; i++)
            fn_80146F88(i, 1);
    }

    if (fn_8013FDD4(self) == 0) {
        fn_8014B130(10);
        netReport__FPCce(base + 0x90);
        fn_800C8F68(base + 0xb0);
        return 0;
    }

    if (g_NtMatchingStatus != 9) {
        fn_8014B130(10);
        netReport__FPCce(base + 0xc0, g_NtMatchingStatus);
        fn_800C8F68(base + 0xfc);
        return 0;
    }

    if (self->state == 0 && self->state == 1) {
        fn_8014B130(10);
        netReport__FPCce(base + 0x10c, self->state);
        fn_800C8F68(base + 0x13c);
        return 0;
    }

    netReport__FPCce(base + 0x150);
    u8 m = 0;
    for (int i = 0; i < 4; i++) {
        if (m < lbl_805A0418[i].b)
            m = lbl_805A0418[i].b;
    }

    int unit = self->x54;
    self->x4c = m * unit;
    int v50 = unit * lbl_805A0418[lbl_8059E742].b;
    int port = (self->port2 / 1000) * 1000;
    self->state = 2;
    self->x1cc = 0;
    self->x50 = v50;
    self->port = port;
    return 1;
}
