#pragma force_active on
typedef unsigned int u32;

struct Vec3f {
    float x, y, z;
};

struct MuObject {
    unsigned char pad[0x3C];
    Vec3f position;
};

struct MenuTour {
    unsigned char pad0[0xB90];
    u32 count;
    unsigned char pad1[0xF14 - 0xB94];
    u32 indices[4];
    u32 current;
    u32 selected;
    unsigned char pad2[0xF3C - 0xF2C];
    float values[4];
    u32 next;
    unsigned char pad3[0xFD0 - 0xF50];
    MuObject* objects[1];
};

extern "C" void fn_800B6838(MuObject*, const Vec3f*);

extern "C" void fn_3_1F4C(MenuTour* self) {
    for (u32 i = 0; i < self->count; ++i) {
        MuObject* object = self->objects[self->indices[i]];
        Vec3f pos;
        pos.x = object->position.x;
        pos.y = object->position.y;
        pos.z = object->position.z;

        if (i == self->selected) {
            pos.y = self->values[i];
        } else {
            pos.x = self->values[i];
        }

        fn_800B6838(self->objects[self->indices[i]], &pos);
    }

    self->current = self->next;
}
