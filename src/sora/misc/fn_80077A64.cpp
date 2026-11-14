#include <types.h>
#pragma force_active on
struct Entry {
    void* object;
    int id;
    int unk8;
    u32 handle;
    char pad[12];
    u16 count;
    u16 unk1E;
    bool active() const { return handle != (u32)-1 && count != 0; }
    bool present() const { if (active()) return true; return object != 0; }
};
struct SndSystem {
    char pad[0x2D4];
    Entry entries[32];
    u32 index(int id) {
        if (id == -1) return -1;
        bool valid = false;
        u32 slot = (u8)id;
        Entry* entry = &entries[slot];
        if (entry->id == id) { if (entry->present()) valid = true; }
        return valid ? slot : (u32)-1;
    }
    float* get(u32 slot) {
        if (slot == (u32)-1) return 0;
        if (!entries[slot].present()) return 0;
        return entries[slot].object ? (float*)((char*)entries[slot].object + 0x28) : 0;
    }
};
extern "C" const float lbl_805A1AC8;
extern "C" float fn_80077A64(SndSystem* self, int id) {
    float* ptr = self->get(self->index(id));
    float result;
    if (ptr == 0) result = lbl_805A1AC8;
    else result = *ptr;
    return result;
}