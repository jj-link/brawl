#pragma force_active on
struct Obj {
    unsigned char pad0[0xED];
    unsigned char unkED_hi : 5;
    unsigned char unkED_b2 : 1;
    unsigned char unkED_lo : 2;
    unsigned char unkEE_hi : 7;
    unsigned char unkEE_b0 : 1;
    unsigned char unkEF_b7 : 1;
    unsigned char unkEF_rest : 7;
    unsigned char pad1[0x104 - 0xF0];
    unsigned int unk104;
};

extern "C" void fn_800177D4(void* arg0, unsigned int arg1) {
    Obj* o = (Obj*)arg0;
    unsigned int temp_r0;
    unsigned int temp_r4;

    if (o->unkED_b2) {
        if (o->unkEF_b7) {
            if (arg1 < 3) {
                temp_r0 = o->unk104 + 1;
                o->unk104 = temp_r0;
                if (temp_r0 > 0x1E) {
                    o->unkEF_b7 = 0;
                }
            } else {
                o->unk104 = 0;
            }
        } else if (arg1 >= 3) {
            temp_r0 = o->unk104 + 1;
            o->unk104 = temp_r0;
            if (temp_r0 > 0xA) {
                o->unk104 = 0;
                o->unkEF_b7 = 1;
            }
        } else {
            temp_r4 = o->unk104;
            if ((int)temp_r4 != 0) {
                o->unk104 = temp_r4 - 1;
            }
        }
    } else {
        o->unk104 = 0;
        o->unkEE_b0 = 0;
        o->unkEF_b7 = 0;
    }
    o->unkEE_b0 = o->unkEF_b7;
}
