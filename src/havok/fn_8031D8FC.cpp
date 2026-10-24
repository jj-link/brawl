#pragma force_active on

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad[0x60];
    Vec4* a;
    Vec4* b;
    Vec4* c;
    int* index;
};

struct Matrix {
    float m[3][4];
};

extern "C" void fn_8031D8FC(Obj* self, const Matrix* src) {
    Vec4* e = &self->c[*self->index];
    e->x = src->m[0][0];
    e->y = src->m[0][1];
    e->z = src->m[0][2];
    e->w = src->m[0][3];

    e = &self->a[*self->index];
    e->x = src->m[1][0];
    e->y = src->m[1][1];
    e->z = src->m[1][2];
    e->w = src->m[1][3];

    e = &self->b[*self->index];
    e->x = src->m[2][0];
    e->y = src->m[2][1];
    e->z = src->m[2][2];
    e->w = src->m[2][3];

    ++*self->index;
}
