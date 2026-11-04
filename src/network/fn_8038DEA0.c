#pragma force_active on
typedef struct Self {
    char pad[0x18];
    int id;
} Self;

typedef union Value {
    unsigned char byteValue;
    short shortValue;
    int intValue;
    float floatValue;
    long long dateValue;
    struct { int first, second; } pair;
} Value;

typedef struct Field {
    int name;
    int type;
    Value value;
} Field;

extern char lbl_80490FF0[0x98];
extern char lbl_8059FC00[4];
extern char lbl_8059FC04[7];
extern char lbl_8059FC0C[5];
extern char lbl_8059FC14[6];

extern void fn_80364034(int, const char*, const char*);
extern void fn_80364340(int, const char*, const char*);
extern void fn_803646CC(int, const char*, const char*, int);
extern void fn_80364DAC(int, const char*, const char*, int);
extern void fn_80365548(int, const char*, const char*, int);
extern void fn_80365C7C(int, const char*, const char*, float);
extern void fn_803663AC(int, const char*, const char*, int, int);
extern void fn_80366B18(int, const char*, const char*, long long);

void fn_8038DEA0(Self* self, Field* fields, int count)
{
    int i;
    fn_80364034(self->id, lbl_8059FC00, lbl_8059FC04);
    for (i = 0; i < count; fields++, i++) {
        fn_80364034(self->id, lbl_8059FC00, "RecordField");
        fn_803646CC(self->id, lbl_8059FC00, lbl_8059FC0C, fields->name);
        fn_80364034(self->id, lbl_8059FC00, lbl_8059FC14);
        if (fields->type == 0) {
            fn_80364034(self->id, lbl_8059FC00, "byteValue");
            fn_80365548(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.byteValue);
            fn_80364340(self->id, lbl_8059FC00, "byteValue");
        }
        else if (fields->type == 1) {
            fn_80364034(self->id, lbl_8059FC00, "shortValue");
            fn_80365548(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.shortValue);
            fn_80364340(self->id, lbl_8059FC00, "shortValue");
        }
        else if (fields->type == 2) {
            fn_80364034(self->id, lbl_8059FC00, "intValue");
            fn_80365548(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.intValue);
            fn_80364340(self->id, lbl_8059FC00, "intValue");
        }
        else if (fields->type == 3) {
            fn_80364034(self->id, lbl_8059FC00, "floatValue");
            fn_80365C7C(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.floatValue);
            fn_80364340(self->id, lbl_8059FC00, "floatValue");
        }
        else if (fields->type == 4) {
            fn_80364034(self->id, lbl_8059FC00, "asciiStringValue");
            fn_803646CC(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.intValue);
            fn_80364340(self->id, lbl_8059FC00, "asciiStringValue");
        }
        else if (fields->type == 5) {
            fn_80364034(self->id, lbl_8059FC00, "unicodeStringValue");
            fn_80364DAC(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.intValue);
            fn_80364340(self->id, lbl_8059FC00, "unicodeStringValue");
        }
        else if (fields->type == 6) {
            fn_80364034(self->id, lbl_8059FC00, "booleanValue");
            fn_80365548(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.intValue != 0);
            fn_80364340(self->id, lbl_8059FC00, "booleanValue");
        }
        else if (fields->type == 7) {
            fn_80364034(self->id, lbl_8059FC00, "dateAndTimeValue");
            fn_80366B18(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.dateValue);
            fn_80364340(self->id, lbl_8059FC00, "dateAndTimeValue");
        }
        else if (fields->type == 8) {
            fn_80364034(self->id, lbl_8059FC00, "binaryDataValue");
            fn_803663AC(self->id, lbl_8059FC00, lbl_8059FC14, fields->value.pair.first, fields->value.pair.second);
            fn_80364340(self->id, lbl_8059FC00, "binaryDataValue");
        }
        fn_80364340(self->id, lbl_8059FC00, lbl_8059FC14);
        fn_80364340(self->id, lbl_8059FC00, "RecordField");
    }
    fn_80364340(self->id, lbl_8059FC00, lbl_8059FC04);
}
