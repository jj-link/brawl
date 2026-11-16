#pragma force_active on
extern "C" int randi__Fl(long);

extern "C" void fn_65_1A5C(char* self)
{
    unsigned int a;
    unsigned int flag;
    int saved;
    int i;
    unsigned int b;

    flag = 0;
    saved = 0;
    if (*(unsigned int*)(self + 0x9B4) + 0x10000 != 0xFFFF) {
        flag = 1;
        saved = *(unsigned int*)(self + 0x9D8);
    }

    for (int n = 0; n < 10; ++n)
        ((unsigned int*)(self + 0x9B4))[n] = n;

    for (i = 0; i < 32; i++) {
        unsigned int t;

        a = randi__Fl(10);
        if (a >= 9) {
            a = 9;
        }
        b = randi__Fl(10);
        if (b >= 9) {
            b = 9;
        }
        t = *(unsigned int*)(self + (a << 2) + 0x9B4);
        *(unsigned int*)(self + (a << 2) + 0x9B4) = *(unsigned int*)(self + (b << 2) + 0x9B4);
        *(unsigned int*)(self + (b << 2) + 0x9B4) = t;
    }

    if (flag == 1 && *(unsigned int*)(self + 0x9B4) == saved) {
        *(unsigned int*)(self + 0x9B4) = *(unsigned int*)(self + 0x9B8);
    }

    *(unsigned int*)(self + 0x9DC) = 0;
}
