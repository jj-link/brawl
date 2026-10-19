#pragma force_active on
struct Fn66Obj {
    char pad[8];
    int field8;
};

extern "C" void* fn_66_11360(Fn66Obj* self, int index) {
    int sum = (self->field8 >> 29) + index;
    if (sum >= 2) {
        sum -= 2;
    }
    return (char*)self + sum * 0x68 + 0xc;
}
