#pragma force_active on

typedef struct Manager {
    char pad0[0x14];
    int pending;
    char pad18[4];
    int count;
} Manager;

typedef struct Object {
    char pad0[8];
    Manager *manager;
    char padC[0x18];
    int count;
    char pad28[0x70];
    void *table;
} Object;

typedef void (*Callback)(Object *, int, int, int, int);

extern Callback *fn_8035A598(void *, int);
extern void fn_80378018(Manager *);

int fn_80373DCC(Object *self, int index, int a2, int a3, int a4)
{
    Callback *callback;

    if (self == 0) {
        return 1;
    }

    callback = fn_8035A598(self->table, index);
    if (callback == 0) {
        return 1;
    }

    if (a3 == 0 || a2 == 0) {
        a2 = 0;
        a3 = 0;
    }

    self->count++;
    self->manager->count++;
    (*callback)(self, index, a2, a3, a4);
    self->count--;
    self->manager->count--;

    if (self->manager->pending != 0 && self->manager->count == 0) {
        fn_80378018(self->manager);
        return 0;
    }

    return 1;
}
