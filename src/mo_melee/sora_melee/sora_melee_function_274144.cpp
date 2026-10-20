#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

struct grGimmickWarpZone {
    unsigned char padding[0x15C];
    Vec3f position;
    unsigned char attribute;
    bool enabled;
};

extern "C" void setWarpAttrData__17grGimmickWarpZoneFP5Vec3fUcb(
    grGimmickWarpZone* self, Vec3f* position, unsigned char attribute, bool enabled)
{
    self->position.x = position->x;
    self->position.y = position->y;
    self->position.z = position->z;
    self->attribute = attribute;
    self->enabled = enabled;
}
