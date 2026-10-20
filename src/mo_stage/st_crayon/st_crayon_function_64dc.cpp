#pragma force_active on
struct Elem {
    char pad[0xc];
    char data[0x5c];
};

extern "C" void* fn_56_64DC(Elem* p, int i) {
    return &p[i].data;
}
