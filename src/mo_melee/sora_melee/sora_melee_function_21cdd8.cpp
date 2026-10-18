#pragma force_active on
extern "C" {
void fn_27_21FD78(int a);
void fn_27_21CECC(int* a);

void fn_27_21CDD8(int* dest, int a, int b, const char* c) {
    if (b == -1 || a == 0) {
        dest[0] = 0;
        dest[1] = 0;
    } else {
        dest[0] = a;
        dest[1] = 0;
        if (c != 0) {
            if (c[0] == 'A' && c[1] == 'T' && c[2] == 'K' && c[3] == 'D') {
                dest[1] = (int)c;
                fn_27_21FD78(b);
            }
        }
        fn_27_21CECC(dest);
    }
}
}
