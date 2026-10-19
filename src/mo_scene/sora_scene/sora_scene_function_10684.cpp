#pragma force_active on
struct S2 {
    unsigned char pad[8];
    void *value;
};

struct S1 {
    unsigned char pad[12];
    S2 *field;
};

extern "C" void *fn_1_10684(S1 *arg) {
    return arg->field->value;
}
