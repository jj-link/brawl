#pragma force_active on

extern "C" void fn_802C13D0(int, int, int, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3F20;

struct Vtable_Class_802A38DC {
    void* vtable;
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int i;

    Class_802A38DC(int x) {
        i = x;
        f = lbl_805A3F20;
        vtable = lbl_80487198;
    }

    ~Class_802A38DC() {}
};

extern "C" void fn_802B1028(int arg0, int arg1, int arg2, int arg3) {
    Class_802A38DC local0(arg3);
    fn_802C13D0(arg1, arg0, arg2, &local0, lbl_80487198);
}
