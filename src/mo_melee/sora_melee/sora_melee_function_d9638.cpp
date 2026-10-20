#pragma force_active on
struct Obj {
    int pad[2];
    int index;
    unsigned char data[1];
};

extern "C" void *fn_27_D9638(Obj *p, int i) {
    int x = (p->index >> 27) + i;
    if (x >= 14)
        x -= 14;
    return (char *)p + x * 0x30 + 0x0C;
}
