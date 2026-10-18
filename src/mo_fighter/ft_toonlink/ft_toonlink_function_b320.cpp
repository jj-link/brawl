#pragma force_active on
typedef unsigned int u32;

struct FnTable121 {
    char pad[0xc];
    u32 *counts;
};

extern "C" void fn_121_B320(FnTable121 *self, u32 index) {
    self->counts[index]++;
}
