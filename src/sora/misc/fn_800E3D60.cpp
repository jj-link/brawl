#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct Model {
    char pad[0x3C];
    Vec3f position;
};

struct Motion {
    int delay;
    float x, y;
};

struct Animation {
    Motion motion[19];
    int timer;
};

struct Object {
    char pad0[0x14];
    int state;
    char pad18[0x18];
    Model* special;
    char pad34[0xC];
    Model* models[19];
    char pad8C[0xA0];
    Animation animation;
};

extern "C" void fn_800B6838(Model*, const Vec3f*);
extern "C" float lbl_805A2418;

extern "C" int fn_800E3D60(Object* self) {
    Vec3f positions[19];
    Object* current;
    Vec3f* position;
    Animation* animation;
    Motion* motion;
    int i;

    animation = &self->animation;
    float gravity = lbl_805A2418;
    motion = animation->motion;
    current = self;
    position = positions;
    i = 0;

    do {
        Model* model;
        if (i == 18)
            model = self->special;
        else
            model = current->models[0];

        position->x = model->position.x;
        position->y = model->position.y;
        position->z = model->position.z;

        if (motion->delay > 0) {
            --motion->delay;
        } else {
            position->x += motion->x;
            position->y += motion->y;
            fn_800B6838(model, position);
            motion->y -= gravity;
        }

        ++i;
        current = reinterpret_cast<Object*>(
            reinterpret_cast<char*>(current) + 4);
        ++position;
        ++motion;
    } while (i < 19);

    if (--animation->timer <= 0)
        return 4;

    return self->state;
}
