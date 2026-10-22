#include <types.h>
#pragma force_active on

struct Owner;
struct Entry { char pad[0x15]; u8 kind; };
struct Resource { char pad[0xE]; u16 count; u32 tableOffset; };
struct Record {
    u32 pad[2];
    Owner* owner;
    u16 index;
    u16 tail;
    void init(Owner* value, u16 idx) { owner = value; index = idx; }
};
struct Owner {
    char pad0[0xC];
    Resource* resource;
    char pad10[8];
    Record* records;
};

extern "C" s32 fn_8018C114(void*, Entry*);
extern "C" void fn_8018AC64(void*, Record*);

extern "C" void fn_8018B6B8(Owner* self, char* other) {
    u32* offsets = (u32*)((char*)self->resource + self->resource->tableOffset);
    for (u16 i = 0; i < self->resource->count; ++i) {
        Entry* entry = (Entry*)((char*)self->resource + offsets[i]);
        if (entry->kind == 1 && fn_8018C114(other + 0x44, entry)) {
            self->records[i].init(self, i);
            fn_8018AC64(other, &self->records[i]);
        }
    }
}
