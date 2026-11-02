#pragma force_active on

extern "C" void fn_802BBC8C(int, int, int, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3F94;

struct Vtable_Class_802A38DC {
    void* vtable;
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int d;

    Class_802A38DC(int x) {
        d = x;
        f = lbl_805A3F94;
        vtable = lbl_80487198;
    }

    ~Class_802A38DC() {}
};

extern "C" void fn_802BD350(int a, int b, int c, int d) {
    Class_802A38DC local(d);
    fn_802BBC8C(b, a, c, &local);
}