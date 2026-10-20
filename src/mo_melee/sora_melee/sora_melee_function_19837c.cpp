#pragma force_active on
typedef unsigned int u32;

struct Target {
    char pad[8];
    u32 a : 8;
    u32 b : 4;
    u32 c : 20;
};

extern "C" {
void fn_27_19837C(struct Target* self, u32 v) {
    self->b = v;
}
}
