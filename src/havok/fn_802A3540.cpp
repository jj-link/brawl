#pragma force_active on

extern "C" void fn_802A2BE0(int, int, int, int, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3ED0;

struct Vtable_Class_802A38DC {
    void* vtable;
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int i;

    Class_802A38DC(int x) {
        i = x;
        f = lbl_805A3ED0;
        vtable = lbl_80487198;
    }
    ~Class_802A38DC() {}
};

extern "C" void fn_802A3540(int a0, int a1, int a2, int a3, int a4) {
    Class_802A38DC local0(a4);
    fn_802A2BE0(a0, a2, a1, a3, &local0, lbl_80487198);
}
