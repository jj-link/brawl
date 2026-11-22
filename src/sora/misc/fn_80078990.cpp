#include <types.h>
#include <ut/ut_relocate.h>
#pragma force_active on

extern "C" s32 fn_8004F978(u32);
extern char lbl_80454498[];

struct Entry {
    s32 id;
    u32 category;
    u32 sentinel;
    char padding[0x24];
};

struct Context {
    char padding[0x194];
    Entry* entries;
    u32 count;
    u32 categoryCount[24];
    u32 indices[24][50];
    u32 validCount;
    char padding2[0x10];
    u8* data;
    u32 size;
};

extern "C" void fn_80078990(Context* self) {
    int i = 0;
    Context* counts = self;
    Context* indices = self;

    for (; i < 24;
         counts = (Context*)((char*)counts + 4), i++,
         indices = (Context*)((char*)indices + 200)) {
        counts->categoryCount[0] = 0;
        for (int j = 0; j < 50; j++) {
            indices->indices[0][j] = 0;
        }
    }

    self->validCount = 0;
    utRelocate reloc(self->data, self->size);
    self->entries = (Entry*)reloc.getPublicAddress(lbl_80454498);
    self->count = 0;

    while (self->entries[self->count].sentinel != 0xffffffff) {
        self->count++;
    }

    u32 offset;
    u32 index = 0;
    offset = 0;
    while (index < self->count) {
        Entry* entry = (Entry*)((char*)self->entries + offset);

        switch (entry->id) {
        case 0x2709:
        case 0x27b9:
        case 0x27ba:
        case 0x27bb:
        case 0x27bc:
        case 0x27bd:
        case 0x27be:
            break;

        default:
            if (fn_8004F978(entry->id)) {
                self->validCount++;
                u32 category = entry->category;
                if (category < 21) {
                    self->indices[category][self->categoryCount[category]] = index;
                    self->categoryCount[category]++;
                }
            }
            break;
        }

        offset += 0x30;
        ++index;
    }
}
