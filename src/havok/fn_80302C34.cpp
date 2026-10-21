#pragma force_active on
extern "C" {

struct type_80302C34 {
    unsigned short unk0;
    unsigned short unk2;
    unsigned short unk4;
    unsigned short unk6;
    unsigned char unk8;
    unsigned char unk9;
    unsigned char unkA;
    unsigned char unkB;
};

void fn_80302C34(struct type_80302C34* out, const struct type_80302C34* in) {
    out->unk0 = in->unk0;
    out->unk2 = in->unk2;
    out->unk4 = in->unk4;
    out->unk6 = in->unk6;
    out->unk8 = in->unk8;
    out->unk9 = in->unk9;
    out->unkA = in->unkA;
    out->unkB = in->unkB;
}

}
