#pragma force_active on
extern "C" {
int fn_800B5854(void*, int, int, int, int);
int fn_10_14620(void*, int);

struct Obj {
    char pad[0x1b4];
    int field_1b4;
};

struct Self {
    char pad[4];
    void* field_4;
    char pad2[4];
    void* field_c;
    char pad3[4];
    Obj* field_14;
};

int fn_10_1BE5C(Self* self) {
    int val;
    if (self->field_14->field_1b4 == 1) {
        val = fn_10_14620(self->field_14, 1) - 1;
    } else {
        val = 0;
    }
    fn_800B5854(self->field_4, val, 0x10, 1, 0);

    int val2;
    if (self->field_14->field_1b4 == 1) {
        val2 = fn_10_14620(self->field_14, 1) - 1;
    } else {
        val2 = 4;
    }
    return fn_800B5854(self->field_c, val2, 0x10, 1, 0);
}
}
