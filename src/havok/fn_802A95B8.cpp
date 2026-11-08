#pragma force_active on
extern "C" void fn_802A7F30(int, int, int, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3EF8;
struct Vtable_Class_802A38DC {
    void* vtable;
};
class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    int i;
    Class_802A38DC(int x) {
        i = x;
        f = lbl_805A3EF8;
        vtable = lbl_80487198;
    }
    ~Class_802A38DC() {}
};
extern "C" void fn_802A95B8(int a0, int a1, int a2, int a3) {
    Class_802A38DC local0(a3);
    fn_802A7F30(a1, a0, a2, &local0, lbl_80487198);
}
