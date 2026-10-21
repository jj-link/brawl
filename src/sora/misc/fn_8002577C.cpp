#pragma force_active on
extern "C" {
extern unsigned char lbl_80494EE8[];

void fn_8002577C(int index, unsigned char value) {
    lbl_80494EE8[index * 0x68] = value;
}
}
