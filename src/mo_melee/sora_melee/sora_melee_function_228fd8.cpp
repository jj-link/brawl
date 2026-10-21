#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct ModelEntry {
    u8 pad[0xE8];
    void* resource;
};

struct Model {
    u8 pad[0x44];
    ModelEntry** entries;
};

struct Slot {
    u8 unused : 1;
    u8 active : 1;
    u8 flags : 6;
    u8 modelIndex;
    u8 materialIndex;
    u8 pad[5];
    Model* model;
};

struct Ref {
    u8 active;
    u8 pad[3];
    u32 id;
    u32 unk8;
    u8 count;
    u8 padD[3];
};

struct State {
    u8 pad[0x9C];
    Slot slots[36];
    Ref refs[4];
};

struct Material {
    u8 pad[0x30];
    s32 offset;
};

extern "C" Material* fn_8018F2EC(void*, u32);
extern "C" u32 fn_801926CC(void**);

extern "C" void fn_27_228FD8(State* self, Model* model)
{
    Slot* slot = self->slots;
    for (u32 i = 0; i < 36; ++i, ++slot) {
        if (slot->active && slot->model == model) {
            slot->active = 0;
            void* resource = slot->model->entries[slot->modelIndex]->resource;
            Material* mat = fn_8018F2EC(&resource, slot->materialIndex);
            void* data = mat->offset ? (u8*)mat + mat->offset : 0;
            u32 id = fn_801926CC(&data);
            Ref* ref = self->refs;
            while (i < 4) {
                if (ref->active && ref->id == id) {
                    if (--ref->count == 0)
                        ref->active = 0;
                    break;
                }
                ++ref;
            }
        }
    }
}
