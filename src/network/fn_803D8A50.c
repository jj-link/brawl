#pragma force_active on
typedef unsigned int u32;

struct S {
    u32 flags;
    void *arg;
};

extern int fn_803D7B04(void *, void *);
extern int fn_803D7C00(void *);
extern int fn_803D7FD0(void *, int);
extern int fn_803D835C(void *);

int fn_803D8A50(struct S *self) {
    int result;

    if (self->flags & 8) {
        goto flag_set;
    }

    result = fn_803D7B04(self->arg, self);
    if (result != 0) {
        return result;
    }

    result = fn_803D7C00(self->arg);
    if (result != 0) {
        return result;
    }

    result = fn_803D835C(self);
    if (result == 0) {
        goto success;
    }

    fn_803D7FD0(self->arg, 0);
    return result;

flag_set:
    return 12;

success:
    self->flags = (self->flags & ~2u) | 8;
    return 0;
}
