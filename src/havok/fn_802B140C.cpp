#pragma force_active on
extern "C" void fn_802AFD30(void* a, void* b, void* c, void* d, void* e);
extern "C" char lbl_80487178[];

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

extern "C" void fn_802B140C(void* arg1, void* arg2, void* arg3, void* arg4, int arg5) {
    Class_802A3938 local0;
    local0.v = arg5;
    local0.c = 0;
    local0.vtable = lbl_80487178;
    fn_802AFD30(arg1, arg3, arg2, arg4, &local0);
}
