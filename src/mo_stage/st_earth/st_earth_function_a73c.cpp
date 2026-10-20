#pragma force_active on
extern "C" {
struct S { unsigned char a; signed int f : 4; unsigned int g : 4; unsigned char c; unsigned char d; };
int fn_66_A73C(const void *o) {
    struct S *s = (struct S *)((const char *)o + 8);
    return s->f;
}
}
