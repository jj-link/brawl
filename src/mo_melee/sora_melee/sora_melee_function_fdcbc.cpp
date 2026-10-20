#pragma force_active on
struct Obj {
    int pad[6];
    int value;
};

extern "C" int* fn_27_FDCBC(Obj* p, int index) {
    int n = (p->value >> 30) + index;
    if (n >= 1)
        --n;
    return (int*)((char*)p + n * 12 + 0x1c);
}
