#pragma force_active on
typedef unsigned short u16;
struct MuObject;
struct State {
    unsigned char pad0[0x44];
    MuObject* object;
    unsigned char pad48[0x1A4];
    u16 frame;
    u16 delta;
    unsigned char pad1F0[0x1E8];
    u16 count;
};
extern "C" void fn_16_32E8(State*, u16, u16);
extern "C" void setFrameNode__8MuObjectFf(MuObject*, float);
extern "C" void setFrameVisible__8MuObjectFf(MuObject*, float);
extern "C" void fn_16_347C(State* self) {
    fn_16_32E8(self, self->frame, self->delta);
    setFrameNode__8MuObjectFf(self->object, (float)self->frame);
    MuObject* object = self->object;
    int sum = self->frame + self->delta;
    int flags = 0;
    if (sum > 0) flags |= 2;
    if (sum < self->count - 1) flags |= 1;
    setFrameVisible__8MuObjectFf(object, (float)flags);
}
