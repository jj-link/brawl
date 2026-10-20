#pragma force_active on
struct StVec3Holder {
    char pad[0x10];
    float x;
    float y;
    float z;
};

extern "C" {
void fn_49_39A0(StVec3Holder* self, float x, float y, float z)
{
    self->x = x;
    self->y = y;
    self->z = z;
}
}
