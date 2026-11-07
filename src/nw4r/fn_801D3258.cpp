#pragma force_active on
extern "C" {
extern float lbl_8040AFC0[];
extern float lbl_8040AFF0[];
extern const float lbl_805A3678;
extern const float lbl_805A367C;
extern const float lbl_805A3680;
float fn_801D3258(int x) {
    float result = lbl_805A3678;
    int octave = 0;
    while (x < 0) { x += 0xc00; --octave; }
    while (x >= 0xc00) { x -= 0xc00; ++octave; }
    while (octave > 0) { result *= lbl_805A367C; --octave; }
    while (octave < 0) { result *= lbl_805A3680; ++octave; }
    int a = x / 256;
    x %= 256;
    if (a) result *= lbl_8040AFC0[a];
    if (x) result *= lbl_8040AFF0[x];
    return result;
}
}