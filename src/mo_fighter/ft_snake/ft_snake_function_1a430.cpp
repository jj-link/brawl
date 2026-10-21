#pragma force_active on

struct SnakeInitializeObject {
    unsigned char prefix[0x60];
};

struct SnakeInitializeVector {
    float x, y, z;
};

struct SnakeInitializeFlags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct SnakeInitializeParam {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    SnakeInitializeVector position;
    float facing;
    int parameter, reserved2, situation, status, reserved3, motion, reserved4;
    SnakeInitializeFlags flags;
};

extern "C" {
extern const float lbl_122_rodata_BC;
void fn_27_1D8370(void*, const SnakeInitializeParam*);

void fn_122_1A430(void* object, int resource, int team, int parameter) {
    SnakeInitializeVector position = {
        lbl_122_rodata_BC,
        lbl_122_rodata_BC,
        lbl_122_rodata_BC
    };
    SnakeInitializeParam initialize;
    initialize.resource = resource;
    initialize.team = team;
    initialize.teamOwner = team;
    initialize.teamAnother = team;
    initialize.index = -1;
    initialize.owner = -1;
    initialize.reserved0 = 0;
    initialize.reserved1 = 0;
    __memcpy(&initialize.position, &position, sizeof(position));
    initialize.facing = lbl_122_rodata_BC;
    initialize.parameter = parameter;
    initialize.reserved2 = 0;
    initialize.situation = 2;
    initialize.status = 0x80;
    initialize.reserved3 = 0;
    initialize.motion = 0x35f;
    initialize.reserved4 = 0;
    initialize.flags.first = 1;
    initialize.flags.second = 1;
    initialize.flags.third = 0;
    initialize.flags.fourth = 0;
    initialize.flags.fifth = 1;
    initialize.flags.sixth = 0;
    initialize.flags.seventh = 0;
    initialize.flags.eighth = 0;
    initialize.flags.ninth = 0;
    initialize.flags.tenth = 0;
    fn_27_1D8370(object, &initialize);
}
}
