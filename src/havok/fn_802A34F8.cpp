#pragma force_active on
// The classes and the object this function's exception table needs, written by decomp-orchestrator.
// Keep them and write the rest of the function so its code matches. Add members as the code needs.

extern "C" void fn_802A3138(int, int, void*, void*, void*);

extern "C" char lbl_80487178[];  // the vtable of Class_802A3938, under its name in the game
struct Vtable_Class_802A3938 {
    void* vtable;
};
class Class_802A3938 : public Vtable_Class_802A3938 {
public:
    char flag;
    int m;
    Class_802A3938(int x) {
        m = x;
        flag = 0;
        vtable = lbl_80487178;
    }
    ~Class_802A3938() {}
};

extern "C" void fn_802A34F8(int arg0, int arg1, void* arg2, int arg3) {
    Class_802A3938 local0(arg3);
    fn_802A3138(arg1, arg0, arg2, &local0, lbl_80487178);
}
