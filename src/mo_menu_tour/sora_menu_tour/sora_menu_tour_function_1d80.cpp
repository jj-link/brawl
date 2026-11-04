#include <mu/mu_object.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct Tour {
    char pad0[0xb90];
    unsigned int count;
    char pad1[0xf14 - 0xb94];
    unsigned int indices[4];
    unsigned int frame;
    unsigned int axis;
    float start[4];
    float end[4];
    unsigned int duration;
    char pad2[0xfd0 - 0xf50];
    MuObject* objects[1];
};

extern "C" void fn_800B6838(MuObject*, const Vec3f*);

extern "C" int fn_3_1D80(Tour* self) {
    Vec3f laterPos;
    ++self->frame;
    if (self->frame >= self->duration) {
        for (unsigned int i = 0; i < self->count; ++i) {
            MuObject* obj = self->objects[self->indices[i]];
            Vec3f pos;
            pos = *(Vec3f*)((char*)obj + 0x3c);
            if (i == self->axis)
                pos.m_y = self->end[i];
            else
                pos.m_x = self->end[i];
            fn_800B6838(self->objects[self->indices[i]], &pos);
        }
        self->frame = self->duration;
        return 1;
    }
    for (unsigned int i = 0; i < self->count; ++i) {
        MuObject* obj = self->objects[self->indices[i]];
        float value = (float)self->frame * (self->end[i] - self->start[i]) / (float)self->duration;
        laterPos = *(Vec3f*)((char*)obj + 0x3c);
        if (i == self->axis)
            laterPos.m_y = value + self->start[i];
        else
            laterPos.m_x = value + self->start[i];
        fn_800B6838(self->objects[self->indices[i]], &laterPos);
    }
    return 0;
}