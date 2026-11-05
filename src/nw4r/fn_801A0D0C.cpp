#pragma force_active on
extern "C" {
extern int lbl_804A46F0[4];
extern signed char lbl_805A0548;
extern float lbl_804A9A58[10];
int fn_801627CC(float*, void*);
float* fn_801A0D0C(int index) {
    if (lbl_804A46F0[1])
        return (float*)(lbl_804A46F0[1] + index * 0x24);
    if (!lbl_805A0548)
        lbl_805A0548 = 1;
    void* p;
    if (lbl_804A46F0[0])
        p = (void*)(lbl_804A46F0[0] + index * 0x30);
    else
        p = 0;
    if (!fn_801627CC(lbl_804A9A58, p)) {
        lbl_804A9A58[8] = 1.0f;
        lbl_804A9A58[4] = 1.0f;
        lbl_804A9A58[0] = 1.0f;
        lbl_804A9A58[7] = 0.0f;
        lbl_804A9A58[6] = 0.0f;
        lbl_804A9A58[5] = 0.0f;
        lbl_804A9A58[3] = 0.0f;
        lbl_804A9A58[2] = 0.0f;
        lbl_804A9A58[1] = 0.0f;
    }
    return lbl_804A9A58;
}
}