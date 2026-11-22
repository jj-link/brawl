#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern "C" int __cntlzw(unsigned int);

struct TimerEntry {
    const char* name;
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
extern char lbl_80413438[];

class Heap {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual unsigned int slot3(unsigned int);
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    unsigned int f4;
    unsigned int f8;
    unsigned int fC;
    unsigned int cur;
    unsigned int f14;
    unsigned int hw;
    unsigned int limit;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12(void*, void*);
};

extern Heap* lbl_805A0EC8;

extern "C" {
void fn_802EFF2C(void* self, void* msg);
void fn_802EB810(void* a, void* b, void* c);
void fn_802EFE70(void* self);
void fn_8027EABC(void* heap, void* data, unsigned int size, int code);
}

struct Self {
    char pad0[0x54];
    Object_vptr_0* obj54;
    char pad1[0x6c - 0x58];
    void* field6C;
    char pad2[0x78 - 0x70];
    int pending;
    int busy;
    char pad3[0x84 - 0x80];
    signed char active;
    char pad4[0x2e4 - 0x85];
    int n;
};

struct Msg {
    signed char type;
    char pad[3];
    void* obj;
    signed char active;
    char pad2[3];
};

struct PtrList {
    void* data;
    s32 size;
    u32 capacity;
    u32 savedTop;

    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity << 3, 0x15); }
};

inline void initList(PtrList* list, unsigned int n) {
    list->data = 0;
    list->size = 0;
    list->capacity = 0x80000000;
    unsigned int cur = lbl_805A0EC8->cur;
    unsigned int size = ((n << 3) + 0x10) & ~0xfu;
    unsigned int newTop = cur + size;
    if (newTop <= lbl_805A0EC8->limit) {
        lbl_805A0EC8->cur = newTop;
    } else {
        cur = lbl_805A0EC8->slot3(size);
    }
    list->data = (void*)cur;
    list->capacity = n | 0x80000000;
    list->savedTop = cur;
}

inline void restoreTop(unsigned int top) {
    Heap* heap = lbl_805A0EC8;
    heap->cur = top;
    if (top == heap->hw) {
        heap->slot4();
    }
}

inline void processList(PtrList* list, Self* self, void* obj) {
    int i;
    char* base;
    int off;
    base = (char*)obj + 0x30;
    i = 0;
    off = 0;
    while (i < list->size) {
        char* node = *(char**)((char*)list->data + off + 4);
        if (node != base) {
            fn_802EB810(obj, node + (signed char)node[5], self->field6C);
        }
        i++;
        off += 8;
    }
}

extern "C" void fn_802EB97C(Self* self, void* obj, s32 active) {
    if (((const s32*)self)[0x7c / 4] != 0) {
        Msg msg;
        msg.type = 0x13;
        msg.obj = obj;
        msg.active = (signed char)active;
        fn_802EFF2C(self, &msg);
        return;
    }
    self->busy++;

    {
        Timer* timer = &lbl_80532448;
        signed char c = (signed char)(((unsigned int)timer->end <<
            __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31);
        if (((unsigned int)(-c | c) >> 31) != 0) {
            TimerEntry* e = timer->current;
            e->name = lbl_80413438 + 0x19;
            ((TimerEntry*)((char*)e + 0xc))->name = lbl_80413438 + 0x31;
            register u32 t;
            asm { mftb t }
            e->time = t;
            timer->current = (TimerEntry*)((char*)e + 0x10);
        }
    }

    PtrList list;
    initList(&list, self->n);

    self->obj54->slot12((void*)((unsigned long)obj + 0x30), &list);

    {
        Timer* timer = &lbl_80532448;
        signed char c = (signed char)(((unsigned int)timer->end <<
            __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31);
        if (((unsigned int)(-c | c) >> 31) != 0) {
            TimerEntry* e = timer->current;
            e->name = lbl_80413438 + 0x3e;
            register u32 t;
            asm { mftb t }
            e->time = t;
            timer->current = (TimerEntry*)((char*)e + 0xc);
        }
    }

    processList(&list, self, obj);

    if (active != 0) {
        Timer* timer = &lbl_80532448;
        signed char c = (signed char)(((unsigned int)timer->end <<
            __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31);
        if (((unsigned int)(-c | c) >> 31) != 0) {
            TimerEntry* e = timer->current;
            e->name = lbl_80413438 + 0x4f;
            register u32 t;
            asm { mftb t }
            e->time = t;
            timer->current = (TimerEntry*)((char*)e + 0xc);
        }
        ((Object_vptr_0*)obj)->slot10();
    }

    if (--self->busy == 0 && self->pending != 0 && ((unsigned int)(-(int)self->active | (int)self->active) >> 31) == 0) {
        fn_802EFE70(self);
    }

    {
        Timer* timer = &lbl_80532448;
        signed char c = (signed char)(((unsigned int)timer->end <<
            __cntlzw((unsigned int)timer->end ^ (unsigned int)timer->current)) >> 31);
        if (((unsigned int)(-c | c) >> 31) != 0) {
            TimerEntry* e = timer->current;
            e->name = lbl_80413438 + 0x62;
            register u32 t;
            asm { mftb t }
            e->time = t;
            timer->current = (TimerEntry*)((char*)e + 0xc);
        }
    }

    restoreTop(list.savedTop);
    if (list.isOwned()) {
        list.dealloc();
    }
}
