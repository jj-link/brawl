#pragma force_active on
extern const unsigned char lbl_80487828[0x40];

struct Unk3A {
    unsigned char unk0[6];
    unsigned short unk6;
};

extern "C" void fn_802D650C(Unk3A* arg0) {
    if (arg0 != 0) {
        arg0->unk6 = 1;
        *(const unsigned char**)&arg0->unk0[0] = lbl_80487828;
    }
}
