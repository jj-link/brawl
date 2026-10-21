#pragma force_active on
typedef struct Context Context;

typedef struct Callbacks {
    unsigned char pad[0x14];
    int (*operation)(Context *, int, int, int, int *);
} Callbacks;

struct Context {
    int field_0;
    Callbacks *callbacks;
    unsigned char pad_8[0xC];
    int field_14;
    unsigned char pad_18[0x14];
    int field_2C;
};

extern int fn_803D781C(Context *, int, int, int, int *, int *);
extern void fn_803D78CC(Context *, int, int, int, int *, int *);
extern void fn_803D8994(int, int);
extern int fn_803EC3D4(int);
extern int fn_803EC418(int);

int fn_803D7DC8(Context *self, int arg1, int arg2, int arg3,
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
    if (fn_803EC3D4(self->field_14) != 0) {
        return 0x14;
    }
    result = self->callbacks->operation(self, arg1, sp10, spC, arg5);
    if (fn_803EC418(self->field_14) != 0) {
        return 0x14;
    }
    fn_803D78CC(self, sp10, *arg5, arg4, &sp8, arg5);
    if (result != 0) {
        fn_803D8994(self->field_2C, result);
        return 0x15;
    }
    return 0;
}
