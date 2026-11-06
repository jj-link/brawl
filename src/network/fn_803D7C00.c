#pragma force_active on
typedef struct Session Session;
typedef struct Table Table;
struct Table {
    char pad[8];
    int (*func8)(Session *);
    char pad_c[16];
    int (*func1c)(Session *, void *);
};
struct Session {
    unsigned int flags;
    Table *table;
    char pad_8[6];
    short count;
    char pad_10[4];
    int field_14;
    char field_18[12];
    unsigned int field_24;
    char pad_28[4];
    int field_2c;
};
extern int fn_803EC3D4(int);
extern int fn_803EC418(int);
extern void fn_803D8994(int, int);
int fn_803D7C00(Session *self) {
    int result;
    if (self->count != 0) goto increment;
    if (fn_803EC3D4(self->field_14) != 0) return 0x14;
    result = self->table->func8(self);
    if (result != 0) {
        if (fn_803EC418(self->field_14) != 0) return 0x14;
        fn_803D8994(self->field_2c, result);
        return 0x15;
    }
    result = self->table->func1c(self, self->field_18);
    if (fn_803EC418(self->field_14) != 0) return 0x14;
    if (result != 0) {
        fn_803D8994(self->field_2c, result);
        return 0x15;
    }
    if (self->field_24 & 1) self->flags |= 2;
    else self->flags &= ~2;
increment:
    self->count += 1;
    return 0;
}