#pragma force_active on
typedef struct Inner {
    char pad0[0x14];
    int field_14;
    char pad18[4];
    int field_1c;
} Inner;

typedef struct Outer Outer;
struct Outer {
    char pad0[8];
    Inner *manager;
    char pad0C[0x18];
    int counter;
    char pad28[8];
    void (*func)(Outer *, void *);
};

extern void fn_80378018(Inner *);

int fn_80373C54(Outer * const self, void *arg1) {
    Inner *manager;
    int temp;

    if (self == 0) return 1;
    if (self->func == 0) return 1;
    {
        Inner *manager = self->manager;
        temp = self->counter;
        self->counter = temp + 1;
        ++manager->field_1c;
    }
    self->func(self, arg1);
    self->counter--;
    manager = self->manager;
    manager->field_1c--;
    manager = self->manager;
    if (manager->field_14 != 0 && manager->field_1c == 0) {
        fn_80378018(manager);
        return 0;
    }
    return 1;
}