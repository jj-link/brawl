#pragma force_active on
struct StageData {
    unsigned int padding[2];
    unsigned int flags;
};

extern "C" void fn_40_116DC(StageData* self) {
    self->flags |= 0x00010000u;
}
