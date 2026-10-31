#pragma force_active on

extern "C" {

extern const unsigned char lbl_80406968[];

unsigned char fn_8004F370(int arg0) {
    const unsigned char* p = lbl_80406968;
    int idx;
    int i;

    for (i = 0, idx = 0; i < 14; i++) {
        if (arg0 == p[2]) {
            return (lbl_80406968 + idx * 4)[3];
        }
        p += 4;
        idx++;
    }

    return 0x80;
}

}
