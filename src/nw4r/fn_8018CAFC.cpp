#pragma force_active on

struct Color {
    unsigned char r, g, b, a;
};

extern "C" void fn_8018C464(Color*, const Color*, int);
extern "C" void fn_8018C59C(int, int, int, int, const Color*);

extern "C" void fn_8018CAFC(int a, int b, int c, int d,
                            const Color* input, int mode)
{
    Color colors[4];
    *(unsigned int*)&colors[0] = 0xFFFFFFFF;
    *(unsigned int*)&colors[1] = 0xFFFFFFFF;
    *(unsigned int*)&colors[2] = 0xFFFFFFFF;
    *(unsigned int*)&colors[3] = 0xFFFFFFFF;

    if (input) {
        int i = 0;
        const Color* src = input;
        Color* dst = colors;
        do {
            Color result;
            Color temp = *src;
            fn_8018C464(&result, &temp, mode);
            *dst = result;
            ++i;
            ++src;
            ++dst;
        } while (i < 4);
    }

    fn_8018C59C(a, b, c, d, input ? colors : 0);
}
