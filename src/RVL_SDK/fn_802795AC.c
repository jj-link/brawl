#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    float x;
    float y;
    float z;
} Vec3f;

typedef struct {
    unsigned char pad0[0xc];
    float x;
    float y;
    float z;
    u8 flag;
    unsigned char pad1[3];
    u32 mask;
} Obj;

void fn_802795AC(Obj* self, u32 bits, Vec3f* v) {
    if ((bits & self->mask) == 0) {
        return;
    }
    self->x = v->x;
    self->y = v->y;
    self->z = v->z;
    self->flag = 1;
}
