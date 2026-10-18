#pragma force_active on
typedef unsigned int u32;

struct Fn118A528Owner {
    char pad[0xc];
    u32 *values;
};

extern "C" void fn_118_A528(Fn118A528Owner *self, u32 amount, u32 index) {
    self->values[index] -= amount;
}
