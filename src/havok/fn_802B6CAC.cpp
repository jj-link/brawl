#pragma force_active on

extern "C" void fn_802B528C(void*, void*, int, int, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3F58;

struct Vtable_Class_802A38DC {
    void* vtable;
    Vtable_Class_802A38DC() : vtable(lbl_80487198) {}
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int v;

    Class_802A38DC() : f(lbl_805A3F58) {}
    ~Class_802A38DC() {}
};

extern "C" void fn_802B6CAC(void* a, int b, void* c, int d, int e, int f, int g) {
    Class_802A38DC local0;
    local0.v = e;
    local0.f = lbl_805A3F58;
    local0.vtable = lbl_80487198;
    fn_802B528C(a, c, b, d, &local0);
}
