#pragma force_active on
struct S { float a, b, c; char d, e, f, g; };
extern const float lbl_27_rodata_7B8;
extern "C" void fn_27_5AB60(S* s) {
    s->e = 0;
    s->a = s->b = s->c = lbl_27_rodata_7B8;
    s->d = 0;
    s->f = 0;
    s->g = 0;
}
