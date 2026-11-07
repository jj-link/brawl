#pragma force_active on
struct Vec { float x, y, z; };
struct Self {
    char pad0[0x150];
    unsigned char state;
    char pad151[0xf];
    Vec* points;
    char pad164[4];
    float* limit;
    char pad16c[4];
    float* speed;
    float* active;
    unsigned char index;
    char pad179[7];
    Vec pos;
};
extern "C" const float lbl_88_rodata_118[];
extern "C" void fn_88_628C(Self* self) {
    const float* constants = lbl_88_rodata_118;
    if ((int)self->state != 2) return;
    if (*self->active > constants[0])
        self->pos.x -= *self->speed;
    if (self->pos.x < *self->limit - constants[2]) {
        switch (self->index) {
        case 2:
            self->pos.x = constants[1] + self->points[3].x;
            if (*self->active > constants[0])
                self->pos.x -= *self->speed;
            break;
        case 3: self->pos.x = constants[1] + self->points[0].x; break;
        case 4: self->pos.x = constants[1] + self->points[1].x; break;
        case 5: self->pos.x = constants[1] + self->points[2].x; break;
        }
    }
    switch (self->index) {
    case 2: self->points[0] = self->pos; break;
    case 3: self->points[1] = self->pos; break;
    case 4: self->points[2] = self->pos; break;
    case 5: self->points[3] = self->pos; break;
    }
}