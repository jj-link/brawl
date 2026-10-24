#pragma force_active on

struct S {
    int n;
    float x;
    float y;
    float z;

    void set(float c, float b, float a) {
        n = 0;
        x = a;
        y = b;
        z = c;
    }
};

extern float lbl_805A1DE8;
extern float lbl_805A1DEC;
extern float lbl_805A1DF0;

extern "C" void fn_8009E3D0(S* s) {
    s->set(lbl_805A1DF0, lbl_805A1DEC, lbl_805A1DE8);
}
