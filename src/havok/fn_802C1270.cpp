#include <types.h>

#pragma force_active on
#pragma use_lmw_stmw on

extern "C" int __cntlzw(unsigned int);

class ShapeSub {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(void*, void*);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3(void*, void*, void*, void*);
};

struct Shape {
    char pad[0xc];
    ShapeSub sub;
};

struct Body {
    void* shape;
    void* key;
    unsigned int data;
    Body* parent;
};

struct Pair {
    void* key;
    Object_vptr_0* obj;
};

struct Coll {
    char pad[0xc];
    Pair* pairs;
    int count;
};

struct TimerEntry {
    char* name;
    unsigned int time;
    unsigned int unused;
};

struct Timer {
    unsigned int unused0;
    TimerEntry* current;
    unsigned int unused8;
    TimerEntry* end;
    unsigned int unused10[2];
};

extern Timer lbl_80532448;
extern char lbl_8040FF38[];

#define RECORD(offset) { \
    Timer* timer = &lbl_80532448; \
    signed char c = (signed char)(((unsigned int)timer->end << __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31); \
    if (((unsigned int)(-c | c) >> 31) != 0) { \
        TimerEntry* entry = timer->current; \
        entry->name = lbl_8040FF38 + (offset); \
        register u32 t; \
        asm { mftb t } \
        entry->time = t; \
        timer->current = entry + 1; \
    } \
}

extern "C" void fn_802C1270(Coll* self, Body* arg1, void* a2, void* a3, void* a4) {
    void* key;
    Shape* shape;
    Pair* p;
    int i;

    RECORD(0)

    __attribute__((aligned(16))) unsigned char buffer[0x200];
    Body body;
    unsigned int d = arg1->data;
    body.parent = arg1;
    shape = (Shape*)arg1->shape;
    body.data = d;
    p = self->pairs;

    for (i = self->count - 1; i >= 0; i--) {
        key = p->key;
        body.shape = shape->sub.slot4(key, buffer);
        body.key = key;
        p->obj->slot3(&body, a2, a3, a4);
        p++;
    }

    RECORD(0x12)
}
