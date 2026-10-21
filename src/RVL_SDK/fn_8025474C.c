#pragma force_active on
extern void fn_80254F00(void* p, int a, int b, int c, int d, int e);

void fn_8025474C(unsigned char* p, int a, int b, int c, int d) {
    if (p[0x6c] == 5) {
        fn_80254F00(p, a, 0, b, c, d);
    }
}
