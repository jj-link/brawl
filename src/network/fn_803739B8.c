#pragma force_active on
typedef struct Object Object;

typedef void (*Callback)(Object *, Object *, int, int, int, int, int);

struct Object {
    char pad0[0x14];
    int pending;
    char pad18[4];
    int count;
    Callback first;
    int refs;
};

extern void fn_80378018(Object *);

int fn_803739B8(Object *self, Object *other, int a2, int a3, int a4, int a5, int a6)
{
    if (self == 0 || other == 0) {
        return 1;
    }

    if (self->first == 0) {
        return 1;
    }

    if (a6 == 0 || a5 == 0) {
        a5 = 0;
        a6 = 0;
    }

    self->count++;
    other->refs++;

    self->first(self, other, a2, a3, a4, a5, a6);

    self->count--;
    other->refs--;

    if (self->pending != 0 && self->count == 0) {
        fn_80378018(self);
        return 0;
    }

    return 1;
}
