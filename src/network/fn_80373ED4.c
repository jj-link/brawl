#pragma force_active on

typedef struct Object Object;

typedef struct Owner {
    char pad0[0x14];
    int pending;
    char pad18[4];
    int count;
} Owner;

typedef void (*Callback)(Object *, int, int, int, int);

struct Object {
    char pad0[8];
    Owner *owner;
    char padC[0x18];
    int refs;
    char pad28[0x74];
    void *table;
};

extern Callback *fn_8035A598(void *, int);
extern void fn_80378018(Owner *);

int fn_80373ED4(Object *self, int a1, int a2, int a3, int a4)
{
    Callback *callback;

    if (self == 0) {
        return 1;
    }

    callback = fn_8035A598(self->table, a1);
    if (callback == 0) {
        return 1;
    }

    if (a3 == 0 || a2 == 0) {
        a2 = 0;
        a3 = 0;
    }

    self->refs++;
    self->owner->count++;

    (*callback)(self, a1, a2, a3, a4);

    self->refs--;
    self->owner->count--;

    if (self->owner->pending != 0 && self->owner->count == 0) {
        fn_80378018(self->owner);
        return 0;
    }

    return 1;
}
