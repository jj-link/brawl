#include <types.h>
#pragma force_active on
struct Data { int a; float b, c; int d, e; u8 f, g; int h; };
struct Slot { char pad[8]; int id; u8 c, d, active; char pad2; u32 timer; Data data; };
struct Slot2 { char pad[20]; Data data; };
struct DS { Data data; char pad[12]; };
struct DS2 { Data data; char pad[12]; };
struct Obj { char pad[0x28]; int value; };
extern "C" Obj* fn_40_15694(void*, int);
extern "C" Data fn_40_155A0(void*, int, int, int, Data*);
extern "C" void fn_40_15BB4(void*, Data*);
extern "C" void fn_40_15C3C(void*, int);
extern "C" void fn_40_15C1C(void*, int);
extern "C" void fn_40_15C5C(void*, int);
extern "C" void fn_40_16AC4(Slot* self) {
    Slot* p = self;
    Slot2* c = (Slot2*)self;
    DS2* b;
    DS* a = (DS*)((u8*)self + 0x14);
    b = (DS2*)a;
    int i = 0;
    do {
        if (p->active) {
            int id = p->id;
            Obj* obj = fn_40_15694(self, id);
            if (obj) {
                c->data = fn_40_155A0(self, id, obj->value, i, &a->data);
            }
            fn_40_15BB4(self, &b->data);
            if (p->c) {
                fn_40_15C3C(self, i);
                p->c = 0;
            }
            if (p->d) {
                fn_40_15C1C(self, i);
                p->active = 0;
                p->d = 0;
                p->id = -1;
            }
            if (p->timer > 300) {
                fn_40_15C5C(self, i);
                p->active = 0;
            } else {
                p->timer++;
            }
        }
        i++;
        p = (Slot*)((u8*)p + 40);
        a++;
        c = (Slot2*)((u8*)c + 40);
        b++;
    } while (i < 2);
}