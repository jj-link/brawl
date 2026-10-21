#pragma force_active on
extern "C" {

extern const float lbl_805A2C48;
void fn_801EC7B8(float f);

int fn_80162974(int arg0, float farg0) {
    fn_801EC7B8(lbl_805A2C48 * farg0);
    return arg0;
}

}
