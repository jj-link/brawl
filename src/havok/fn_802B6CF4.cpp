#pragma force_active on

extern "C" void fn_802B52A0(int, int, int, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3F58;

struct Vtable_Class_802A38DC {
    void* vtable;
    Vtable_Class_802A38DC() {}
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int i;

    Class_802A38DC(int x) {
        i = x;
        f = lbl_805A3F58;
        vtable = lbl_80487198;
    }

    ~Class_802A38DC() {}
};

extern "C" void fn_802B6CF4(int arg0, int arg1, int arg2, int arg3) {
    Class_802A38DC local0(arg3);
    fn_802B52A0(arg1, arg0, arg2, &local0);
}
