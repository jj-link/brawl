#pragma force_active on
typedef unsigned int u32;

struct Flags {
    unsigned int pad : 10;
    unsigned int value : 10;
    unsigned int rest : 12;
};

extern "C" void fn_27_1A45DC(void* self, u32 value) {
    Flags* p = (Flags*)((char*)self + 8);
    p->value = value;
}
