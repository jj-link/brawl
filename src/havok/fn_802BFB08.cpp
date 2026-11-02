#pragma force_active on

extern "C" void fn_802BE124(int, int, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3F9C;

struct Vtable_Class_802A38DC {
    void* vtable;
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int i;
    Class_802A38DC(int x) {
        i = x;
        f = lbl_805A3F9C;
        vtable = lbl_80487198;
    }
    ~Class_802A38DC() {}
};

extern "C" void fn_802BFB08(int arg0, int arg1, void* arg2, int arg3) {
    Class_802A38DC local0(arg3);
    fn_802BE124(arg1, arg0, arg2, &local0);
}
