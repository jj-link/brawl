#include <types.h>
#pragma force_active on

extern "C" int __cntlzw(unsigned int);

struct Elem {
    Elem() {}
    unsigned char raw[0x30];
};
struct Ent {
    unsigned char pad[0x10];
    unsigned char flag;
};
struct Ctx {
    unsigned char* base;
    unsigned char pad4[8];
    unsigned char flag;
    unsigned char pad0d[0x1b];
    Ent* ent;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(int, int, Ctx*, Elem**);
};
struct Rec {
    unsigned char pad0[3];
    unsigned char size;
    unsigned char pad4[4];
    signed char type;
    unsigned char pad9[7];
    Object_vptr_0* obj;
    int a;
    int b;
};
struct Sub {
    unsigned char pad0[0x48];
    Rec** arr;
    int count;
    unsigned char pad1[8];
    unsigned int end;
    unsigned char pad2[2];
    unsigned short stride;
};
struct Scan {
    Elem* cursor;
    unsigned char pad0[0xc];
    Elem buf[256];
    unsigned char pad1[0x20];
    float best;
    unsigned char pad2[0x1c];
    int n;
    unsigned char pad3[0xc];
};
struct ProfRec {
    const char* name;
    unsigned int time;
    unsigned int pad;
};
struct ProfBuf {
    unsigned int pad0;
    ProfRec* cur;
    unsigned int pad8;
    ProfRec* end;
    unsigned char flag;
};
struct TmCtx {
    int pad0;
    int state;
    int limit;
    int padc;
    int pad10;
    int off;
    int pad18[4];
    int base;
};
extern ProfBuf lbl_80532448;
extern char lbl_80414580[];
extern float lbl_805A4814;
extern TmCtx* lbl_805A0EB8;
extern "C" void fn_802FF784(Rec*, Ctx*, Elem**, Ent*);
extern "C" void fn_80327CDC(void*, Elem**, Rec*);

#define RECORD(offset) { \
    ProfBuf* timer = &lbl_80532448; \
    signed char test = (signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->cur)) >> 31); \
    if (((unsigned int)(-test | test) >> 31) != 0) { \
        ProfRec* entry = timer->cur; \
        entry->name = lbl_80414580 + (offset); \
        register u32 t; asm { mftb t } \
        entry->time = t; \
        timer->cur = entry + 1; \
    } \
}

inline int remaining() {
    TmCtx* tm = lbl_805A0EB8;
    int sum = tm->base + tm->off;
    return tm->limit <= sum ? 0 : tm->limit - sum;
}

extern "C" void fn_8032786C(void* a, Sub* b, Ctx* c) {
    RECORD(0x8e)
    __declspec(align(16)) Scan scan;
    float big = lbl_805A4814;
    scan.best = big;
    Rec* stop;
    int idx = 0;
    while (idx < b->count) {
        Rec* r = b->arr[idx];
        idx++;
        if (idx == b->count) {
            stop = (Rec*)((char*)r + b->end);
        } else {
            stop = (Rec*)((char*)r + b->stride);
        }
        while (r < stop) {
            int v14 = r->a;
            int v18 = r->b;
            Ent* e = (Ent*)(c->base + r->type * 0x3c + 0x1a28);
            c->ent = e;
            c->flag = e->flag;
            scan.cursor = scan.buf;
            scan.best = big;
            scan.n = 0;
            fn_802FF784(r, c, &scan.cursor, e);
            if (remaining() == 0) {
                lbl_805A0EB8->state = 1;
            }
            if (lbl_805A0EB8->state == 1) {
                RECORD(0x17)
                return;
            }
            unsigned char same = scan.cursor == scan.buf;
            if (((unsigned int)(-(signed char)same | (signed char)same) >> 31) == 0) {
                r->obj->slot5(v14, v18, c, &scan.cursor);
            }
            signed char changed = big != scan.best;
            if (((unsigned int)(-changed | changed) >> 31) != 0) {
                fn_80327CDC(a, &scan.cursor, r);
            }
            r = (Rec*)((char*)r + r->size);
        }
    }
    RECORD(0x17)
}
