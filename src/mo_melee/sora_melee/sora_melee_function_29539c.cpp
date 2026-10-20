#pragma force_active on
typedef struct Obj {
    char pad[0x18];
    int field;
} Obj;

extern "C" char* fn_27_29539C(Obj* self, int idx) {
    int n = (self->field >> 26) + idx;
    if (n >= 20) {
        n -= 20;
    }
    return (char*)self + n * 12 + 0x1c;
}
