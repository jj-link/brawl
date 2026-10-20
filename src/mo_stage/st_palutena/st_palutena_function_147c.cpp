#pragma force_active on
struct FighterVec {
    char pad[0x1b0];
    float x;
    float y;
    float z;
};

extern "C" {
void fn_67_147C(FighterVec* self, float x, float y, float z) {
    self->x = x;
    self->y = y;
    self->z = z;
}
}
