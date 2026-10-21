#pragma force_active on
extern float lbl_80532500[];
extern float lbl_805A3D3C;
extern float lbl_805A3D40;

void fn_80285A48(void) {
    lbl_80532500[0] = lbl_805A3D40;
    lbl_80532500[1] = lbl_805A3D40;
    lbl_80532500[2] = lbl_805A3D40;
    lbl_80532500[3] = lbl_805A3D3C;
}

__declspec(section ".ctors") extern void* const fn_80285A48_ctor = (void*)fn_80285A48;
