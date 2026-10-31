#pragma force_active on
extern "C" void fn_802C4164(void*, void*, void*, void*, void*);

extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3FD0;

struct Vtable_Class_802A38DC {
    void* vtable;
    Vtable_Class_802A38DC() : vtable(lbl_80487198) {}
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int value;

    Class_802A38DC() {}
    ~Class_802A38DC() {}
};

extern "C" void fn_802C5A0C(void* a, void* b, void* c, void* d, void* e) {
    Class_802A38DC local0;
    local0.f = lbl_805A3FD0;
    local0.value = (int)e;
    local0.vtable = lbl_80487198;
    fn_802C4164(a, c, b, d, &local0);
}
