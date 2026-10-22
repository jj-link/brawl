#pragma force_active on

struct Entry {
    int a, b, c, d;
    unsigned char e, f;
    int g, h;
    float* p;
    int i;
    float* q;
    int j, k;
};

struct Vec {
    Entry* data;
    int size;
    unsigned int capacity;
};

struct Object {
    unsigned char pad[0x34];
    Vec vec;
};

extern "C" void fn_8027CE3C(Vec*, int);
extern float lbl_80532550[4];

extern "C" void fn_802D5AB0(Object* self, const Entry* src) {
    if (self->vec.size == (int)(self->vec.capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(&self->vec, 0x30);
    }

    Entry* dst = &self->vec.data[self->vec.size++];
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    dst->h = src->h;
    dst->p = src->p;
    dst->i = src->i;
    dst->q = src->q;
    dst->j = src->j;
    dst->k = src->k;

    if (dst->p == 0) {
        dst->k = 1;
        dst->q = lbl_80532550;
        dst->p = lbl_80532550;
    }
}
