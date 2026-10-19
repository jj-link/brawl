#pragma force_active on
struct Fn68Obj {
    int pad[2];
    int value;
};

extern "C" {
void* fn_68_D7D8(Fn68Obj* self, int index) {
    int shift = self->value >> 28;
    int sum = shift + index;
    if (sum >= 7) {
        sum -= 7;
    }
    return (char*)self + (sum << 3) + 12;
}
}
