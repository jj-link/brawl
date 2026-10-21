#pragma force_active on
extern "C" {
void fn_80185CBC(char *arg0, unsigned int arg1, signed char arg2) {
    unsigned int hi = arg1 & ~3u;
    unsigned int lo = arg1 & 3u;
    char *p = arg0 + hi;
    p = p + lo;
    *(signed char *)(p + 0xE4) = arg2;
}
}
