#pragma force_active on
extern "C" {
extern char lbl_80487178[16];
void fn_802C5280(void* unused, void* a, int b, int c, void* d);
}

struct Vtable_Class_802A3938 {
    void* vtable;
    Vtable_Class_802A3938() : vtable(lbl_80487178) {}
};
class Class_802A3938 : public Vtable_Class_802A3938 {
public:
    unsigned char c;
    int v;
    Class_802A3938() : c(0) {}
    ~Class_802A3938() {}
};

extern "C" void fn_802C597C(void* arg1, void* arg2, void* arg3, int arg4, int arg5) {
    Class_802A3938 local0;
    local0.c = 0;
    local0.v = arg5;
    local0.vtable = lbl_80487178;
    fn_802C5280(arg1, arg3, (int)arg2, arg4, &local0);
}
