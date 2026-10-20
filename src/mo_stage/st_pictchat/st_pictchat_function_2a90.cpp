#pragma force_active on
struct Obj {
    char pad[0x184];
    char a;
    int b;
    float c;
};

extern "C" void fn_73_2A90(Obj* o, char a, int b, float c) {
    o->a = a;
    o->b = b;
    o->c = c;
}
