#pragma force_active on
extern "C" {

extern const unsigned char lbl_804069A0[0x3C8];

int fn_8004F2BC(int idx) {
    return lbl_804069A0[idx * 8];
}

}
