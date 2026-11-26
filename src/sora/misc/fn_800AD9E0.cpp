#include <types.h>
#include <ut/ut_relocate.h>
#include <gm/gm_global.h>
#include <string.h>
#pragma force_active on

extern char lbl_80455180[];

extern "C" u8 fn_8004EAC8(u8**);
extern "C" s32 fn_800568A0();
extern "C" s32 fn_8005680C(s32);
extern "C" void fn_800ADD1C(void*, u32, int);

struct Entry {
    s32 id;
    char pad04[0x25];
    u8 mask;
    char pad2a[0x32];
    u32 value;
    u32* data;
};

struct Context {
    Entry* entries;
    u32* vertData;
    u32* vertList;
    u32 selectedCount;
    u32 selectedTotal;
    u16 values[1000];
    u32 indices[1000];
    u32 selected[1000];
    bool flags[1000];
    u8 states[1000];
    u32 count;
    u32 available;
    u32 obtained;
    u32 mask;
    u32 complete;
    u32 sorted[1000];
};

extern "C" void fn_800AD9E0(Context* self, u8* data, u32 size) {
    u32 base = (u32)lbl_80455180;
    utRelocate rel(data, size);

    self->entries = (Entry*)rel.getPublicAddress((char*)(base + 0x1c));
    self->vertData = (u32*)rel.getPublicAddress((char*)(base + 0x28));
    self->vertList = (u32*)rel.getPublicAddress((char*)(base + 0x38));

    memset(self->flags, 0, 1000);
    memset(self->states, 0, 1000);
    self->count = 0;
    self->available = 0;
    self->obtained = 0;
    self->mask = 1;
    self->complete = 0;
    memset(self->sorted, 0, 4000);

    do {
        if (self->entries[self->count].id >= 0)
            self->count++;
    } while (self->entries[self->count].id >= 0);

    u16* records = (u16*)((u8*)g_GameGlobal->m_record + 0xd56);
    if (fn_8004EAC8((u8**)g_GameGlobal) == 0)
        self->mask = 1;
    else
        self->mask = 2;

    for (u32 i = 0; i < self->count; i++) {
        s32 index = -1;
        if (fn_800568A0() > 0)
            index = fn_8005680C(self->entries[i].id);

        if (index >= 0) {
            self->values[i] = records[index + 1] & 0x3ff;
            self->flags[i] = !(records[index + 1] & 0x4000U);
            self->states[i] = (records[index + 1] >> 15) & 1;

            if (self->flags[i] == 1 && self->states[i] == 1)
                self->complete++;
            if (self->states[i] == 1)
                self->obtained++;
            if (self->states[i] == 1 &&
                (self->mask & self->entries[i].mask))
                self->available++;
        }
        self->indices[i] = i;
    }

    for (u16 i = 0; i < self->count; i++) {
        self->entries[i].value = self->vertData[i + 1];
        self->entries[i].data =
            &self->vertList[self->vertData[self->vertData[0] + i + 1]];
    }

    self->selectedCount = 1000;
    u32 i = 0;
    u32* dst = (u32*)self;
    for (; i < self->selectedCount; dst++, i++)
        dst[0x1784 / 4] = 0;

    self->selectedCount = 0;
    self->selectedTotal = self->count;
    fn_800ADD1C(self, 5, 1);

    for (u32 i = 0; i < self->complete; i++)
        self->sorted[i] = self->indices[i];
}
