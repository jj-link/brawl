#pragma force_active on
extern "C" {
int fn_10_14620(void*, int);
int fn_800B5854(void*, int, int, int, int);

struct muInner {
    char pad[0x1b4];
    int field_1b4;
};

struct muSelCharMenu {
    void* field_00;
    void* field_04;
    void* field_08;
    void* field_0c;
    void* field_10;
    muInner* field_14;
};

int fn_10_1BEF8(muSelCharMenu* self) {
    int idx1;
    if (self->field_14->field_1b4 == 1) {
        idx1 = fn_10_14620(self->field_14, 1) - 1;
    } else {
        idx1 = 0;
    }
    fn_800B5854(self->field_04, idx1, 0x10, 1, 0);
    int idx2;
    if (self->field_14->field_1b4 == 1) {
        idx2 = fn_10_14620(self->field_14, 1) - 1;
    } else {
        idx2 = 4;
    }
    return fn_800B5854(self->field_0c, idx2, 0x10, 1, 0);
}
}
