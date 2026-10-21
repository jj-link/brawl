#pragma force_active on
typedef struct Context Context;

typedef struct Operations {
    char pad[0x18];
    int (*call)(Context *, int, int, int, int *);
} Operations;

struct Context {
    int unk0;
    Operations *ops;
    char pad8[0xC];
    int lock;
    char pad18[0x14];
    int error;
};

extern int fn_803D781C(Context *, int, int, int, int *, int *);
extern void fn_803D78CC(Context *, int, int, int, int *, int *);
extern void fn_803D8994(int, int);
extern int fn_803EC3D4(int);
extern int fn_803EC418(int);

int fn_803D7ECC(Context *self, int arg1, int arg2, int arg3,
                int arg4, int *arg5)
{
    int sp10;
    int spC;
    int sp8;
    int result;
    int status;

    status = fn_803D781C(self, arg2, arg3, arg4, &sp10, &spC);
    if (status != 0) {
        return status;
    }
    if (fn_803EC3D4(self->lock) != 0) {
        return 0x14;
    }

    result = self->ops->call(self, arg1, sp10, spC, arg5);
    if (fn_803EC418(self->lock) != 0) {
        return 0x14;
    }

    fn_803D78CC(self, sp10, *arg5, arg4, &sp8, arg5);
    if (result != 0) {
        fn_803D8994(self->error, result);
        return 0x15;
    }
    return 0;
}
