#pragma force_active on

struct Matrix {
    unsigned int m[12];
};

struct Vec {
    float x, y, z;
};

struct Object {
    char pad0[0x64];
    unsigned char flags;
    signed char field65;
    char pad66[0x2a];
    Vec translation;
    Vec scale;
    Vec rotation;
    char padb4[8];
    char* holder;
    char padc0[0x34];
    Object* parent;
    char padf8[0xc];
    unsigned char dirty;
    char pad105[3];
    Matrix matrix;
};

extern "C" void fn_801EC184(void*, void*);
extern "C" void fn_801669EC(Matrix*, Matrix*, unsigned int, unsigned int, signed char);
extern "C" void fn_80162908(Matrix*, Matrix*, Vec*);
extern "C" void fn_801629AC(Matrix*, float, float, float);
extern "C" void fn_801EC1B8(Matrix*, Matrix*, Matrix*);
extern "C" void fn_801628B4(Matrix*, Matrix*, Vec*);
extern "C" float lbl_805A2C8C;

extern "C" Matrix* fn_80166B8C(Object* self, Matrix* out) {
    Matrix rotation;
    float x, y, z;

    if (self->dirty) {
        if (!self->parent) {
            fn_801EC184(self->holder + 0x54, &self->matrix);
        } else {
            Matrix b;
            fn_80166B8C(self->parent, &b);
            fn_801669EC(&self->matrix, &b, self->flags & 1,
                        (self->flags >> 1) & 1, self->field65);
        }

        fn_80162908(&self->matrix, &self->matrix, &self->translation);
        z = self->rotation.z;
        y = self->rotation.y;
        x = self->rotation.x;
        fn_801629AC(&rotation, lbl_805A2C8C * x,
                    lbl_805A2C8C * y, lbl_805A2C8C * z);
        fn_801EC1B8(&self->matrix, &rotation, &self->matrix);
        fn_801628B4(&self->matrix, &self->matrix, &self->scale);
        self->dirty = 0;
    }

    if (out) {
        *out = self->matrix;
        return out;
    }

    return &self->matrix;
}
