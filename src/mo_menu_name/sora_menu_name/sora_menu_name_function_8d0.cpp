#pragma force_active on
extern "C" void fn_8006BAB0(char*, int, int, int);
extern "C" int fn_8006CEEC(int, int);
extern "C" int strcmp(const char*, const char*);

extern "C" void fn_16_8D0(int unused, char* out, int id, char* name) {
    char buf[8];
    int n = fn_8006CEEC(id, 0x7fff);
    int i = 0;
    while (i < n) {
        buf[0] = 0;
        fn_8006BAB0(buf, id, i, 1);
        if (strcmp(buf, name) == 0) {
            break;
        }
        i++;
    }
    if (i < n) {
        i++;
        if (i >= n) {
            i = 0;
        }
    } else {
        i = 0;
    }
    out[0] = 0;
    fn_8006BAB0(out, id, i, 1);
}
