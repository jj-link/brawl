#pragma force_active on
struct fn27Obj {
    char pad[0x18];
    int flag;
};

extern "C" {
void* fn_27_1AF350(fn27Obj* self, int idx) {
    int sign = self->flag >> 27;
    int n = sign + idx;
    if (n >= 8) {
        n = n - 8;
    }
    return (char*)self + n * 12 + 0x1c;
}
}
