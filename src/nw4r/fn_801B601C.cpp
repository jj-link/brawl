#pragma force_active on
struct Color {
    unsigned char r, g, b, a;
};

extern "C" void fn_801F2400(void*, const Color*);

extern "C" void fn_801B601C(char* arg0, const Color* arg1) {
    Color color = *arg1;
    fn_801F2400(arg0 + 4, &color);
}
