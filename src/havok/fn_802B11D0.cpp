#pragma force_active on

extern "C" void fn_802B8D70(void*, int, int, int, void*);
extern "C" char lbl_80487178[];

struct Vtable_Class_802A3938 {
    void* vtable;
    Vtable_Class_802A3938() : vtable(lbl_80487178) {}
};

class Class_802A3938 : public Vtable_Class_802A3938 {
public:
    char c;
    int v;
    Class_802A3938() {}
    ~Class_802A3938() {}
};

extern "C" void fn_802B11D0(void* arg1, int arg2, int arg3, int arg4, int arg5) {
    Class_802A3938 local0;
    local0.v = arg5;
    local0.c = 0;
    local0.vtable = lbl_80487178;
    fn_802B8D70(arg1, arg3, arg2, arg4, &local0);
}
