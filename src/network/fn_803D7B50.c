#pragma force_active on

typedef struct Session Session;
typedef struct Table Table;

struct Table {
    int (*func)(Session *, Table *);
};

struct Session {
    int field_0;
    Table *table;
    unsigned char pad_8[0x4];
    short count;
    unsigned char pad_E[0x6];
    int field_14;
    unsigned char pad_18[0x14];
    int field_2C;
};

extern int fn_803EC3D4(int);
extern int fn_803EC418(int);
extern void fn_803D8994(int, int);

int fn_803D7B50(Session *self) {
    Table *table;
    int result;

    if (self->count != 0) {
        goto increment;
    }
    if (fn_803EC3D4(self->field_14) != 0) {
        return 0x14;
    }
    table = self->table;
    result = table->func(self, table);
    if (fn_803EC418(self->field_14) != 0) {
        return 0x14;
    }
    if (result != 0) {
        fn_803D8994(self->field_2C, result);
        return 0x15;
    }
increment:
    self->count += 1;
    return 0;
}
