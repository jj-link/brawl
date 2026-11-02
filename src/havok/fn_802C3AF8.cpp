#pragma force_active on

extern "C" void fn_802C2C38(void*, void*, void*, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3FB8;

struct Vtable_Class_802A38DC {
    void* vtable;
    Vtable_Class_802A38DC() : vtable(lbl_80487198) {}
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int v;

    Class_802A38DC() : f(lbl_805A3FB8) {}
    ~Class_802A38DC() {}
};

extern "C" void fn_802C3AF8(void* a, void* b, void* c, void* d, int e) {
    Class_802A38DC local0;
    local0.v = e;
    local0.f = lbl_805A3FB8;
    local0.vtable = lbl_80487198;
    fn_802C2C38(a, c, b, d, &local0);
}
