#include <types.h>
#pragma force_active on

struct Owner;

struct Entry {
    char pad[0x15];
    u8 kind;
};

struct Resource {
    char pad[0xE];
    u16 count;
    u32 tableOffset;
};

struct Record {
    u32 pad[2];
    Owner* owner;
    u16 index;
    u16 tail;

    void init(Owner* value, u16 idx) {
        owner = value;
        index = idx;
    }
};

class Resolver {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void* resolveA(Entry*, void*);
    virtual void* resolveB(Entry*, void*);
};

struct Owner {
    char pad0[0xC];
    Resource* resource;
    char pad10[8];
    Record* records;
};

extern "C" void fn_801832C8(void*, Record*);
extern "C" void fn_8018AC64(void*, Record*);

extern "C" void fn_8018B5B8(Owner* self, Resolver* resolver, void* arg) {
    u32* offsets = (u32*)((char*)self->resource + self->resource->tableOffset);
    for (u16 i = 0; i < self->resource->count; ++i) {
        Entry* entry = (Entry*)((char*)self->resource + offsets[i]);
        if (entry->kind == 0) {
            void* result = resolver->resolveA(entry, arg);
            if (result) {
                self->records[i].init(self, i);
                fn_801832C8(result, &self->records[i]);
            }
        } else {
            void* result = resolver->resolveB(entry, arg);
            if (result) {
                self->records[i].init(self, i);
                fn_8018AC64(result, &self->records[i]);
            }
        }
    }
}
