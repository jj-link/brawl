#pragma force_active on

extern "C" void fn_802A9F04(void*, void*, void*, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3F04;

struct Vtable_Class_802A38DC {
    void* vtable;
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int i;
    Class_802A38DC(int x) {
        i = x;
        f = lbl_805A3F04;
        vtable = lbl_80487198;
    }
    ~Class_802A38DC() {}
};

extern "C" void fn_802AA628(void* a, void* b, void* c, void* d, int e) {
    Class_802A38DC local0(e);
    fn_802A9F04(a, c, b, d, &local0);
}