#include <st/st_trigger.h>
#include <string.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_4BEF8[];
void __dla__FPv(void*);
void __dl__FPv(void*);
void __dt__6gfTaskFv(gfTask*, int);
}

struct Object_vptr_30_base { Object_vptr_30_base* next; char pad[0x2c]; };
class Object_vptr_30 : public Object_vptr_30_base {
public:
    virtual void slot0(int);
};

struct Obj {
    char pad[0x3c];
    char* vptr;
    Object_vptr_30* first;
    int f44;
    int f48;
    void* f4c;
    int f50;
    void* f54;
    int f58;
    char pad5c[4];
    char f60;
};

extern "C" Obj* fn_27_231EA8(Obj* self, int flag) {
    if (self) {
        Object_vptr_30* p = self->first;
        self->vptr = lbl_27_data_4BEF8;
        while (p) {
            Object_vptr_30* next = (Object_vptr_30*)p->next;
            if (p) p->slot0(1);
            p = next;
        }
        self->f44 = 0;
        self->first = 0;
        self->f48 = 0;
        self->f60 = 1;
        self->f50 = 0;
        self->f58 = 0;
        if (self->f4c) memset(self->f4c, 0, 0x200);
        if (self->f54) memset(self->f54, 0, 0x100);
        g_stTriggerMng = 0;
        if (self->f4c) __dla__FPv(self->f4c);
        self->f4c = 0;
        if (self->f54) __dla__FPv(self->f54);
        self->f54 = 0;
        __dt__6gfTaskFv((gfTask*)self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}