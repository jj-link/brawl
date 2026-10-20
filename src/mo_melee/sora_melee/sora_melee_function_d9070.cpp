#pragma force_active on
struct Entry {
    int pad[2];
    int index;
};

extern "C" void *fn_27_D9070(Entry *p, int i) {
    int n = (p->index >> 27) + i;
    if (n >= 8)
        n -= 8;
    return (char *)p + n * 0x34 + 0x0C;
}
