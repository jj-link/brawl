#pragma force_active on
struct Flags {
    unsigned int a : 6;
    unsigned int b : 6;
    unsigned int c : 20;
};

extern "C" void fn_40_1E4F4(void* self, unsigned int v) {
    Flags* p = (Flags*)((char*)self + 8);
    p->b = v;
}
