#pragma force_active on
typedef struct { unsigned char pad[0x24]; unsigned char unk24[0x20]; void* unk44; } S;

extern "C" void fn_800DF298(void* a, int b, int c, void* d);

extern "C" void fn_800DCDDC(S* arg0, int b, int c) {
    fn_800DF298(arg0->unk44, b, c, arg0->unk24);
}
