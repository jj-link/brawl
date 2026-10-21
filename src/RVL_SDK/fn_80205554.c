#pragma force_active on
typedef struct CXUncompContext {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    unsigned char unk14;
} CXUncompContext;

void CXInitUncompContextLZ(CXUncompContext* arg0, int arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = 0;
    arg0->unk11 = 0;
    arg0->unk12 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 3;
    arg0->unk13 = 8;
    arg0->unk14 = 0;
    arg0->unk8 = 0;
}
