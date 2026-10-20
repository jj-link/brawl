#pragma force_active on
struct Stage
{
    float pad[0xD8 / 4];
    float motionSubRatio[4];
};

extern "C" void restoreMotionSubRatio__5StageFi(Stage* self, int index)
{
    const float* src = reinterpret_cast<const float*>(index);
    self->motionSubRatio[0] = src[0];
    self->motionSubRatio[1] = src[1];
    self->motionSubRatio[2] = src[2];
    self->motionSubRatio[3] = src[3];
}
