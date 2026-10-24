#pragma force_active on

extern "C" unsigned int fn_27_263738(void*);
extern "C" void unbindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
extern "C" void fn_56_46BC(void*);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);

struct UnkHeihoStruct {
    float x;
    float y;
};

struct grCrayonYakumonoH {
    char pad0[0x14C];
    void* unk14C;
    char pad150[4];
    void* unk154;
    char pad158[4];
    void* unk15C;
    char pad160[0xC];
    int unk16C;
    float unk170;
    float unk174;
    float unk178;
    float unk17C;
    char pad180[0x38];
    char generator[8];
    int unk1C0;
};

extern "C" void setFallHeiho__17grCrayonYakumonoHF14UnkHeihoStruct14UnkHeihoStructl(
    grCrayonYakumonoH* self, UnkHeihoStruct a, UnkHeihoStruct b, int arg)
{
    self->unk16C = 1;
    self->unk178 = a.x;
    self->unk17C = a.y;
    self->unk170 = b.x;
    self->unk174 = b.y;

    fn_27_263738(self->unk14C);
    unbindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
        self->unk15C, self->unk154);
    fn_56_46BC(self);

    if (arg == 0) {
        self->unk1C0 = playSE__14snd3DGeneratorF5SndIDiii(
            self->generator, 0x1BDD, 0, 0, -1);
    } else {
        self->unk1C0 = playSE__14snd3DGeneratorF5SndIDiii(
            self->generator, 0x1BDF, 0, 0x14, -1);
    }
}
