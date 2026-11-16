#include <types.h>
#include <string.h>
#include <nt/nt_report.h>
#pragma force_active on

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
struct State {
    char pad0[0x14];
    u8 flag;
    char pad15[0xb];
    Elem* elems;
    char pad24[0x24];
    char* buf;
    char pad4c[0x5c];
    int state;
    char padac[0xa0];
    u32 timer;
    char pad150[4];
    u32 size;
    char pad158[8];
    void* data;
    int stride;
    char pad168[0x3f];
    s8 result;
    char pad1a8[0x2a8];
    u32 x450;
    Elem* list;
    Elem* freeList;
};
extern "C" void fn_80142EB0(State*);
static inline void reset(State* self) {
        Elem* e = self->elems;
        int i;
        for (i = 0; i < 20; i++) {
            char* p = self->buf + self->stride * i;
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
        self->x450 = 0; self->list = 0; self->flag = 0;
        self->freeList = self->elems;
        e = self->freeList;
        for (i = 0; i < 20; i++, e++) {
            if (i == 19) e->next = 0;
            else e->next = e + 1;
            e->link = 0;
        }
        memset(self->data, 0, self->size);
}


extern "C" s32 fn_801400EC(State* self) {
    self->result = 0;
    if (g_NtMatchingStatus != 9) return 0;
    switch (self->state) {
    case 0:
        reset(self);
        self->state = 1;
        break;
    case 1:
        break;
    case 2:
    case 3:
    case 4:
    case 5:
        self->timer = 0;
    case 6:
        self->timer++;
        fn_80142EB0(self);
        break;
    }
    return self->result != 0;
}
