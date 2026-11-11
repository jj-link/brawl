#pragma force_active on
#pragma opt_propagation off
#include <types.h>

class Object_vptr_0 {
public:
    virtual void slot0(int);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    u16 active;
    s16 refs;
};

class SoHeapAllocator {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* alloc(int, int);
};

extern SoHeapAllocator* lbl_805A0EB8;
extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_80281BBC(void*, const void*, int);

struct Floats {
    float values[8];
    static void* operator new(unsigned long n) {
        return lbl_805A0EB8->alloc(n, 0x25);
    }
    Floats(const float* a, const float* b) {
        values[0] = a[0];
        values[1] = a[1];
        values[2] = a[2];
        values[3] = a[3];
        values[4] = b[0];
        values[5] = b[1];
        values[6] = b[2];
        values[7] = b[3];
    }
};

struct Payload {
    union {
        Object_vptr_0* object;
        Object_vptr_0** objects;
        void* ptr;
    } data;
    union {
        Object_vptr_0* object;
        Floats* floats;
        u16 count;
        unsigned int word;
    } extra;
    unsigned int wordC;
    unsigned int word10;
};
struct Entry {
    u8 type;
    Payload payload;
};

struct Array {
    Entry* data;
    int size;
    int capacity;
    int getCapacity() const { return capacity & 0x3fffffff; }
};

struct Owner { char padding[0x78]; int count; };
struct Context {
    Array entries;
    Owner* owner;
    Array pending;
    signed char deferred;
};

#define ADD_REF(p) do { Object_vptr_0* ref = (p); if (ref->active != 0) ref->refs++; } while (0)

#define COPY_ARRAY() \
    do { \
        fn_80281BBC( \
            entry->payload.data.objects = (Object_vptr_0**) \
                lbl_805A0EB8->alloc(entry->payload.extra.count * 4, 4), \
            source->payload.data.objects, source->payload.extra.count * 4); \
        Object_vptr_0* ref; \
        Object_vptr_0** p = entry->payload.data.objects; \
        Object_vptr_0** end = p + entry->payload.extra.count; \
        for (; p < end; ) { \
            ref = *p++; \
            if (ref->active != 0) ref->refs++; \
        } \
    } while (0)

extern "C" void fn_802F5E44(Context* self, const Entry* source)
{
    Array* arr = &self->entries;
    if (arr->size == arr->getCapacity())
        fn_8027CE3C(arr, 0x14);
    Entry* entry = &arr->data[arr->size++];
    self->owner->count++;
    fn_80281BBC(entry, source, 0x14);

    switch (entry->type) {
    case 1: ADD_REF(entry->payload.data.object); break;
    case 2: ADD_REF(entry->payload.data.object); break;
    case 4: ADD_REF(entry->payload.data.object); break;
    case 5:
        ADD_REF(entry->payload.data.object);
        ADD_REF(entry->payload.extra.object);
        break;
    case 6: COPY_ARRAY(); break;
    case 7: COPY_ARRAY(); break;
    case 8: ADD_REF(entry->payload.data.object); break;
    case 9: ADD_REF(entry->payload.data.object); break;
    case 10: ADD_REF(entry->payload.data.object); break;
    case 11: ADD_REF(entry->payload.data.object); break;
    case 12:
        ADD_REF(entry->payload.data.object);
        ADD_REF(entry->payload.extra.object);
        if ((unsigned int)(-int(self->deferred) | int(self->deferred)) >> 31) {
            if (self->pending.size == self->pending.getCapacity())
                fn_8027CE3C(&self->pending, 0x14);
            self->pending.data[self->pending.size++] = *entry;
            self->entries.size--;
        }
        break;
    case 13: ADD_REF(entry->payload.data.object); break;
    case 14: ADD_REF(entry->payload.data.object); break;
    case 15: COPY_ARRAY(); break;
    case 16: COPY_ARRAY(); break;
    case 3: ADD_REF(entry->payload.data.object); break;
    case 17: {
        ADD_REF(entry->payload.data.object);
        Floats* copy = new Floats(source->payload.extra.floats->values,
                                  (const float*)(source->payload.extra.word + 16));
        entry->payload.extra.floats = copy;
        break;
    }
    case 18: ADD_REF(entry->payload.data.object); break;
    case 19: ADD_REF(entry->payload.data.object); break;
    case 22: COPY_ARRAY(); break;
    case 21: ADD_REF(entry->payload.data.object); break;
    case 23: ADD_REF(entry->payload.data.object); break;
    case 24: ADD_REF(entry->payload.data.object); break;
    case 25: ADD_REF(entry->payload.data.object); break;
    case 26: ADD_REF(entry->payload.data.object); break;
    case 27: ADD_REF(entry->payload.data.object); break;
    case 28: ADD_REF(entry->payload.data.object); break;
    case 29:
        ADD_REF(entry->payload.data.object);
        self->entries.size--;
        self->owner->count--;
        break;
    case 30: {
        Object_vptr_0* ref = entry->payload.data.object;
        if (ref->active != 0) {
            ref->refs--;
            if (ref->refs == 0 && ref != 0) ref->slot0(1);
        }
        self->entries.size--;
        self->owner->count--;
        break;
    }
    case 32: ADD_REF(entry->payload.data.object); break;
    case 33: ADD_REF(entry->payload.data.object); break;
    case 34: ADD_REF(entry->payload.data.object); break;
    default: break;
    }
}
