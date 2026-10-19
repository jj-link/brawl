#pragma force_active on
// st_pirates: stores two values into the pirate ship stage state object.

struct PirStageState {
    unsigned char unk[0x51C];
    int unk51C;
    int unk520;
    int unk524;
};

extern "C" void fn_52_6D6C(PirStageState* self, int a, int b)
{
    self->unk51C = a;
    self->unk524 = b;
}
