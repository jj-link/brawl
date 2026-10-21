#pragma force_active on
extern "C" {

extern unsigned char lbl_80494EE8[];

unsigned char* fn_800256BC(int idx) {
    return lbl_80494EE8 + idx * 104 + 8;
}

}
