#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef float f32;
typedef unsigned int u32;
typedef int s32;

struct Entry10 {
    u8 pad[4];
    u16 id;
    f32 f;
    u16 flag;
};

struct Owner {
    u8 pad[0x4c];
    Entry10* table4C;
};

struct Out {
    u16 id;
    f32 f;
    u16 flag;
};

extern "C" s32 fn_27_22B010(Owner*, Entry10*, u32, u32*);

extern "C" s32 fn_27_22B444(Owner* self, u32 key, Out* out) {
    u32 idx;

    if (fn_27_22B010(self, self->table4C, key, &idx) != 0) {
        Entry10* e = &self->table4C[idx];
        out->id = e->id;
        out->f = e->f;
        out->flag = e->flag;
        return 1;
    }
    return 0;
}
