#pragma force_active on
extern "C" void fn_802A9EF0(void* a, void* b, void* c, void* d, void* e);
extern "C" char lbl_80487178[];  // the vtable of Class_802A3938, under its name in the game

struct Vtable_Class_802A3938 {
    void* vtable;
    Vtable_Class_802A3938() : vtable(lbl_80487178) {}
};
class Class_802A3938 : public Vtable_Class_802A3938 {
public:
    char c;
    int v;
    Class_802A3938() : c(0) {}
    ~Class_802A3938() {}
};

extern "C" void fn_802AA5E0(void* a, void* b, void* c, void* d, int e) {
    Class_802A3938 local0;
    local0.c = 0;
    local0.vtable = lbl_80487178;
    local0.v = e;
    fn_802A9EF0(a, c, b, d, &local0);
}
