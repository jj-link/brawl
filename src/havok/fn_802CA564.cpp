#pragma force_active on

extern "C" void fn_802C9E4C(int, int, void*, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3FF4;

struct Vtable_Class_802A38DC {
    void* vtable;
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int i;

    Class_802A38DC(int x) {
        i = x;
        f = lbl_805A3FF4;
        vtable = lbl_80487198;
    }

    ~Class_802A38DC() {}
};

extern "C" void fn_802CA564(int arg0, int arg1, void* arg2, int arg3) {
    Class_802A38DC local0(arg3);
    fn_802C9E4C(arg1, arg0, arg2, &local0, lbl_80487198);
}
