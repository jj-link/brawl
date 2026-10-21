#pragma force_active on

struct Obj {
    unsigned int : 3;
    unsigned int value : 3;
    unsigned int : 26;
};

extern "C" void fn_27_1A0D18(void* p, unsigned int v) {
    Obj* o = reinterpret_cast<Obj*>(reinterpret_cast<char*>(p) + 8);
    o->value = v;
}
