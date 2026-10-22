#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

struct Obj {
    int flags;
    unsigned char pad1[0x24];
    float x;
    unsigned char pad2[0xC];
    float y;
    unsigned char pad3[0xC];
    float z;
};

extern "C" {

extern float lbl_805A31F0;

void fn_80195B54(Obj* self, const Vec3* src) {
    if (lbl_805A31F0 == src->x && lbl_805A31F0 == src->y && lbl_805A31F0 == src->z) {
        int result = 0x40;
        if (self->flags & 0x20) {
            result |= 4;
            if (self->flags & 8) {
                result |= 2;
            }
        }
        self->flags |= result;
    } else {
        self->flags &= ~0x46;
    }
    self->x = src->x;
    self->y = src->y;
    self->z = src->z;
}

}
