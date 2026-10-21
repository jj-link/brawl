#pragma force_active on
extern short lbl_805A0A7E;

void fn_802009E8(unsigned int arg0) {
    if (arg0 > 0x8000) {
        arg0 = 0x10000 - 0x8000;
    }
    lbl_805A0A7E = (short)arg0;
}
