#include <types.h>
#pragma force_active on
#pragma use_lmw_stmw on

extern "C" int __cntlzw(unsigned int);
extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_8027EABC(void*, void*, u32, int);
extern "C" void* lbl_805A0EC8;
extern char lbl_80413438[];

struct Pair { void* first; void* second; };

class Object_vptr_0;

struct Array {
    Pair* data;
    int size;
    u32 capacity;
    Pair entries[128];
    Array() { data = entries; size = 0; capacity = 0x80000080; }
    Pair* expand() { return &data[size++]; }
    bool isOwned() const { return (capacity & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, capacity * 8, 0x15); }
    void cleanup() { if (isOwned()) dealloc(); }
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
    virtual void slot12(void*, Array*);
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual u32 slot18(void*, void*);
};

struct Collidable { u8 pad0[5]; s8 ownerOffset; u8 pad6[0x14]; u16 index; };
struct Owner { u8 pad0[0x10]; int offset; u8 pad14[4]; s8 type; };
struct Node { u8 pad0[0x14]; char* a; char* b; };
struct Flags { u8 pad[0x26]; u8 field26 : 2; };

struct Entity {
    u8 pad00[0x1c];
    u8 coll[0x1a];
    u16 index;
    u8 pad38[8];
    Pair* data;
    int size;
    u8 pad48[0x10];
    Flags* flags;
};

struct Context {
    u8 pad0[0x54];
    Object_vptr_0* broadphase;
    void* field58;
    u8 pad5c[0xc];
    void* field68;
    Object_vptr_0* filter;
    char* field70;
    u8 pad74[4];
    int pending;
    int busy;
    u8 pad80[4];
    s8 active;
};

struct Message { s8 type; u8 pad[3]; Entity* entity; s8 mode; s8 update; };

extern "C" void fn_802EFF2C(Context*, Message*);
extern "C" void fn_802EB810(Object_vptr_0*, void*, Object_vptr_0*);
extern "C" void fn_802CB04C(Array*, Array*);
extern "C" void fn_802FF394(void*, void*);
extern "C" void fn_802F377C(void*);
extern "C" void fn_802CAEE8(void*, Pair*, int, void*);
extern "C" void fn_802EFE70(Context*);

struct Trace { char* name; u32 time; u32 unused; char* extra; };
struct TraceState { int unused; Trace* current; int unused2; Trace* end; };
extern TraceState lbl_80532448;

inline void trace(int offset) {
    TraceState* timer = &lbl_80532448;
    Trace* entry = timer->current;
    if ((s8)(((u32)timer->end << __cntlzw((u32)timer->end ^ (u32)entry)) >> 31)) {
        entry->name = lbl_80413438 + offset;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = (Trace*)((char*)entry + 12);
    }
}

inline void traceStart() {
    TraceState* timer = &lbl_80532448;
    Trace* entry = timer->current;
    if ((s8)(((u32)timer->end << __cntlzw((u32)timer->end ^ (u32)entry)) >> 31)) {
        entry->name = lbl_80413438 + 0x65;
        entry->extra = lbl_80413438 + 0x7c;
        register u32 t;
        asm { mftb t }
        entry->time = t;
        timer->current = (Trace*)((char*)entry + 16);
    }
}

inline void processArray(Array* array, Context* self, Entity* entity, int update) {
    int i = 0;
    while (i < array->size) {
        Collidable* col = (Collidable*)array->data[i].second;
        Owner* owner = (Owner*)((char*)col + col->ownerOffset);
        Object_vptr_0* object;
        if (owner->type == 2) object = (Object_vptr_0*)((char*)owner + owner->offset);
        else object = 0;
        if (object != 0) {
            fn_802EB810(object, &entity->coll, self->filter);
            if (update != 0) object->slot10();
            array->data[i--] = array->data[--array->size];
        }
        i = i + 1;
    }
}

extern "C" void fn_802EBCB0(Context* self, Entity* entity, int mode, int update) {
    if (self->busy != 0) {
        Message msg;
        msg.entity = entity;
        msg.type = 0x12;
        msg.mode = mode;
        msg.update = update;
        fn_802EFF2C(self, &msg);
        return;
    }
    traceStart();
    self->busy++;
    Array array;
    if (mode == 0) {
        trace(0x31);
        self->broadphase->slot12((char*)entity + 0x30, &array);
        trace(0x83);
        processArray(&array, self, entity, update);
        Array existing;
        for (int j = 0; j < entity->size; j++) {
            if (existing.size == (int)(existing.capacity & 0x3FFFFFFF)) fn_8027CE3C(&existing, 8);
            Pair* dst = existing.expand();
            dst->first = ((Node*)entity->data[j].first)->a + 0x14;
            dst->second = ((Node*)entity->data[j].first)->b + 0x14;
        }
        fn_802CB04C(&existing, &array);
        existing.cleanup();
    }
    trace(0x8d);
    int k = 0;
    int idx = entity->index * 9;
    for (; k < entity->size; k++) {
        Pair* p = &entity->data[k];
        if ((s8)(self->filter->slot18(&entity->coll, p->second) >> 24) != 0 &&
            ((s8*)(((Collidable*)p->second)->index + idx))[(u32)self->field70 + 0x19d4] != 0) {
            if (update == 1) fn_802FF394(p->first, self->field68);
        } else {
            fn_802F377C(p->first);
            k = k - 1;
            entity->flags->field26 = 1;
        }
    }
    if (array.size > 0) {
        trace(0x99);
        void* f = self->filter;
        if (f != 0) f = (char*)f + 8;
        fn_802CAEE8(self->field58, array.data, array.size, f);
    }
    if (--self->busy == 0 && self->pending != 0 && self->active == 0) fn_802EFE70(self);
    array.cleanup();
    trace(0x62);
}
