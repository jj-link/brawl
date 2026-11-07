#pragma force_active on
typedef struct Session Session;
typedef struct Table Table;
struct Table {
    int pad[3];
    int (*func)(Session *, Table *);
};
struct Session {
    int field_0;
    Table *table;
    unsigned char pad_8[6];
    short count;
    unsigned char pad_10[4];
    int field_14;
    unsigned char pad_18[0x14];
    int field_2C;
};
extern int fn_803EC3D4(int);
extern int fn_803EC418(int);
extern void fn_803D8994(int, int);
int fn_803D7FD0(Session *self, unsigned int arg1) {
    int result = 0;
    if (self->count == 1) {
        Table *table;
        if (fn_803EC3D4(self->field_14) != 0) return 0x14;
        table = self->table;
        result = table->func(self, table);
        if (fn_803EC418(self->field_14) != 0) return 0x14;
        if (result != 0) {
            fn_803D8994(self->field_2C, result);
            result = 0x15;
        }
    } else if (self->count == 0) {
        return 0xE;
    }
    if (result == 0 || arg1 == 1) {
        self->count--;
    }
    return result;
}