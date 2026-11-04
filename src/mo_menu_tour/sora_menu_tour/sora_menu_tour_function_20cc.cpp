#pragma force_active on

struct Vec3f { float x, y, z; };
struct MuObject { char pad[0x3c]; Vec3f position; };

extern "C" void fn_800B6838(MuObject*, const Vec3f*);
extern "C" const double lbl_3_rodata_8140;

struct Menu {
    char pad0[0xf14];
    unsigned int indices[4];
    unsigned int frame;
    unsigned int index;
    float start[4];
    float end[4];
    unsigned int duration;
    char pad1[0xfd0 - 0xf50];
    MuObject* models[4];
};

extern "C" bool fn_3_20CC(Menu* self) {
    Vec3f pos;
    unsigned int f = self->frame + 1;
    self->frame = f;
    if (f >= self->duration) {
        pos = self->models[self->indices[self->index]]->position;
        pos.x = self->end[self->index];
        fn_800B6838(self->models[self->indices[self->index]], &pos);
        self->frame = self->duration;
        return true;
    }
    float x = f * (self->end[self->index] - self->start[self->index]) / self->duration;
    pos = self->models[self->indices[self->index]]->position;
    pos.x = x + self->start[self->index];
    fn_800B6838(self->models[self->indices[self->index]], &pos);
    return false;
}
