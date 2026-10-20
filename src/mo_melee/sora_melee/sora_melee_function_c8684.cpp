#pragma force_active on
typedef struct {
    unsigned char hi : 1;
    unsigned char rest : 7;
    unsigned char pad1[3];
    int pad4;
    int unk8;
    short unkC;
    short unkE;
    signed char unk10;
    signed char unk11;
} FnStruct27;

extern "C" void fn_27_C8684(FnStruct27* p) {
    p->hi = 0;
    p->unk8 = -1;
    p->unkC = 0;
    p->unkE = -1;
    p->unk10 = -1;
    p->unk11 = -1;
}
