#pragma force_active on
struct SoraAdvStageObj {
    int unk0;
    int unk4;
    unsigned int flags;
};

extern "C" {
void fn_40_1E394(SoraAdvStageObj* self) {
    self->flags &= ~0x2000;
}
}
