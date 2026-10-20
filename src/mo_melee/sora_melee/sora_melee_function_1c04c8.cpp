#pragma force_active on
typedef struct Sub {
    int a;
    int b;
    int c;
} Sub;

typedef struct Obj {
    char pad[0x18];
    int field;
    Sub arr[11];
} Obj;

extern "C" Sub* fn_27_1C04C8(Obj* self, int i) {
    int idx = (self->field >> 27) + i;
    if (idx >= 11) {
        idx -= 11;
    }
    return &self->arr[idx];
}
