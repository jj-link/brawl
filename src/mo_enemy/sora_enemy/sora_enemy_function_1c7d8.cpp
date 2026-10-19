#pragma force_active on
struct SoraEnemyUnk {
    char pad0[0x8];
    int unk8;
    char pad0C[0x40];
    float unk4C;
    char pad50[0xB4 - 0x50];
    char unkB4[0x10];
};

extern "C" void fn_41_1BEA8(void* p);
extern "C" float fn_41_10830(void* p);
extern "C" void fn_41_1EF60(SoraEnemyUnk* self, float f);

extern "C" void fn_41_1C7D8(SoraEnemyUnk* self, void* p2, float f) {
    self->unk8 = 0;
    fn_41_1BEA8(self->unkB4);
    self->unk4C = fn_41_10830(p2);
    fn_41_1EF60(self, f);
}
