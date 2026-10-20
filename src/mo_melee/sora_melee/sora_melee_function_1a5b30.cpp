#pragma force_active on
struct Fx {
    unsigned int hi : 10;
    unsigned int f : 10;
    unsigned int lo : 12;
};

extern "C" void fn_27_1A5B30(void* obj, unsigned int v) {
    Fx* p = (Fx*)((char*)obj + 8);
    p->f = v;
}
