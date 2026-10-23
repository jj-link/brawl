#pragma force_active on
// The classes and the object this function's exception table needs, written by decomp-orchestrator.
// Keep them and write the rest of the function so its code matches. Add members as the code needs.

extern "C" void fn_802A8204(void*, void*, void*, void*, void*);
extern "C" char lbl_80487178[];  // the vtable of Class_802A3938, under its name in the game

struct Vtable_Class_802A3938 {
    void* vtable;
    Vtable_Class_802A3938() : vtable(lbl_80487178) {}
};
class Class_802A3938 : public Vtable_Class_802A3938 {
public:
    char c;
    int v;
    Class_802A3938() : c(0) {}
    ~Class_802A3938() {}
};

extern "C" void fn_802A893C(void* arg1, void* arg2, void* arg3, void* arg4, int arg5) {
    Class_802A3938 local0;
    local0.v = arg5;
    local0.c = 0;
    local0.vtable = lbl_80487178;
    fn_802A8204(arg1, arg3, arg2, arg4, &local0);
}
