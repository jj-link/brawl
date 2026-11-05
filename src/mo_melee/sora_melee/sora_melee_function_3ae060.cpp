#pragma force_active on

struct Vec3 {
    float x, y, z;
};

struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3 position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};

struct Object {
    char pad[0x7ce0];
    float unk7ce0;
};

extern "C" {
extern const float lbl_27_rodata_7F6C;
void fn_27_1D8370(void*, const Param*);
void* __memcpy(void*, const void*, unsigned long);

void fn_27_3AE060(Object* object, int team, int parameter, int resource, float facing) {
    Param p;
    Vec3 position;

    object->unk7ce0 = facing;

    position.x = lbl_27_rodata_7F6C;
    position.y = lbl_27_rodata_7F6C;
    position.z = lbl_27_rodata_7F6C;

    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;
    __memcpy(&p.position, &position, sizeof(Vec3));
    p.facing = facing;
    p.parameter = parameter;
    p.variant = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved2 = 0;
    p.motion = 0x35f;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;

    fn_27_1D8370(object, &p);
}
}
