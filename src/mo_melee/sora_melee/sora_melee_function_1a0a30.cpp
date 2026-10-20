#pragma force_active on
struct Entry {
    unsigned char data[0x14];
};

extern "C" void *fn_27_1A0A30(Entry *p, int i) {
    return p[i].data + 0x0C;
}
