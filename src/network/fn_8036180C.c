#pragma force_active on
typedef struct {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    unsigned int unkC;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned short unk1C;
    unsigned char pad1E[0x60 - 0x1E];
    unsigned int unk60;
    unsigned int unk64;
} MD5Ctx;

int fn_8036180C(MD5Ctx *arg0) {
    if (arg0 == 0) {
        return 1;
    }
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk0 = 0x67452301;
    arg0->unk4 = 0xEFCDAB89;
    arg0->unk8 = 0x98BADCFE;
    arg0->unkC = 0x10325476;
    arg0->unk10 = 0xC3D2E1F0;
    arg0->unk60 = 0;
    arg0->unk64 = 0;
    return 0;
}
