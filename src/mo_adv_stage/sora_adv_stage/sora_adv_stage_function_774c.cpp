#pragma force_active on
typedef unsigned int u32;
struct Entry { u32 id; u32 unk; u32 value; u32 unkC; };
struct State { char pad[0x620]; u32 id; };
struct Object {
    char pad0[0x1D0];
    Entry* entries;
    u32 count;
    char pad1[0x524 - 0x1D8];
    State* state;
};
extern const float lbl_40_rodata_A4[];
extern const float lbl_40_rodata_80[];
extern "C" float fn_40_774C(Object* self) {
    if (self->entries) {
        for (u32 i = 0; i < self->count; ++i) {
            if (self->state->id == self->entries[i].id) {
                return lbl_40_rodata_A4[0] * (float)self->entries[i].value;
            }
        }
    }
    return lbl_40_rodata_80[0];
}
