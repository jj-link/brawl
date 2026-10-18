#pragma force_active on
struct Flags {
    unsigned char pad0 : 1;
    unsigned char f : 1;
    unsigned char rest : 6;
};

extern "C" void fn_100_130EC(void* obj, int flag) {
    Flags* s = (Flags*)((char*)obj + 0xA4);
    s->f = flag;
}
