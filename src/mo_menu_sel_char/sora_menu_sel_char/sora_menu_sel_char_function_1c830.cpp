#pragma force_active on
struct FnState {
    char pad[0x40];
    int field40;
    int field44;
};

extern "C" {
void fn_10_1C830(FnState* self, int unused, int val) {
    self->field40 = val;
    self->field44 = 0;
}
}
