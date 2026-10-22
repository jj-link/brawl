#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;
struct Sub { int a; u16 type; u16 b; int c; };
struct Ent { int flags; int a; Sub* p; int d; };
struct Head { char pad[0x68]; struct N* list; };
struct N { u16 pad; u16 count; N* next; Ent e[1]; };
extern void* g_ecMgr;
extern "C" void fn_8005EFF4(void*, void*, void*, int, int);
extern "C" void fn_800141E8(Head* self) {
    Ent* e;
    N* n = self->list;
    for (; n; n = n->next) {
        e = n->e;
        for (u32 i = 0; i < n->count; e++, i++) {
            if ((e->flags >> 24) == 8) {
                Sub* s = e->p;
                if (s) {
                    void* r = s->type == 0x101 ? (void*)((char*)s + 0x10) : 0;
                    if (r) fn_8005EFF4(g_ecMgr, r, s, e->d, 0xff);
                }
            }
        }
    }
}
