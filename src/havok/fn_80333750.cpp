#pragma force_active on

extern "C" {
extern unsigned char lbl_8059F048;
extern unsigned char lbl_8059F049;
extern unsigned char lbl_8059F04A;
extern unsigned char lbl_8059F04B;

void fn_80333750(unsigned char* __restrict out) {
    out[0] = lbl_8059F048;
    out[1] = lbl_8059F049;
    out[2] = lbl_8059F04A;
    out[3] = lbl_8059F04B;
}
}
