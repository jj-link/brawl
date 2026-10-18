#pragma force_active on
struct SoraMinigameObj {
    char pad[0x4c0];
    void *field_4c0;
};

extern "C" {
void fn_20_8290(SoraMinigameObj *self, void *p)
{
    if (self->field_4c0 == p) {
        self->field_4c0 = 0;
    }
}
}
