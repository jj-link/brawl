/* Return a small allocation to its slab, releasing empty slabs and segments. */
typedef unsigned long u32;

typedef struct Segment {
    u32 next;
    u32 prev;
    u32 reserved;
    u32 size_header;
    u32 first_header;
} Segment;

typedef struct FreeSlot {
    u32 owner;
    struct FreeSlot* next;
} FreeSlot;

typedef struct Slab {
    struct Slab* next;
    struct Slab* prev;
    u32 size;
    FreeSlot* free_slots;
    u32 allocated;
} Slab;

typedef struct Bucket {
    Slab* first;
    Slab* last;
} Bucket;

typedef struct Pool {
    u32 head;
    Bucket buckets[6];
} Pool;

extern const u32 lbl_8041F4E8[6];
extern void fn_803F3048(Segment* segment, void* block);
extern void fn_803F2F90(Segment* segment);

void fn_803F3240(Pool* pool, void* payload, u32 size) {
    const u32* limit = lbl_8041F4E8;
    u32 index = 0;
    FreeSlot* slot;
    Slab* slab;
    Bucket* bucket;

    while (size > *limit) {
        limit++;
        index++;
    }
    slot = (FreeSlot*)((char*)payload - 4);
    slab = (Slab*)slot->owner;
    bucket = &pool->buckets[index];
    if (slab->free_slots == 0 && bucket->last != slab) {
        if (bucket->first == slab) {
            bucket->last = bucket->last->next;
            bucket->first = bucket->first->next;
        } else {
            slab->next->prev = slab->prev;
            slab->prev->next = slab->next;
            slab->prev = bucket->last;
            slab->next = slab->prev->next;
            slab->next->prev = slab;
            slab->prev->next = slab;
            bucket->last = slab;
        }
    }
    slot->next = slab->free_slots;
    slab->free_slots = slot;
    if (--slab->allocated == 0) {
        Segment* segment;
        u32 first;
        int whole_free;
        char* block;
        Segment* next;
        Segment* prev;

        if (bucket->last == slab) {
            bucket->last = slab->prev;
        }
        if (bucket->first == slab) {
            bucket->first = slab->next;
        }
        slab->next->prev = slab->prev;
        slab->prev->next = slab->next;
        if (bucket->last == slab) {
            bucket->last = 0;
        }
        if (bucket->first == slab) {
            bucket->first = 0;
        }
        block = (char*)slab - 8;
        segment = (Segment*)(*(u32*)(block + 4) & ~1u);
        fn_803F3048(segment, block);
        first = segment->first_header;
        whole_free = 0;
        if ((first & 2u) == 0 && (first & ~7u) == (segment->size_header & ~7u) - 0x18u) {
            whole_free = 1;
        }
        if (whole_free != 0) {
            prev = (Segment*)segment->prev;
            if (prev == segment) {
                prev = 0;
            }
            if (pool->head == (u32)segment) {
                pool->head = (u32)prev;
            }
            if (prev != 0) {
                next = (Segment*)segment->next;
                prev->next = (u32)next;
                next->prev = (u32)prev;
            }
            segment->prev = 0;
            segment->next = 0;
            fn_803F2F90(segment);
        }
    }
}
