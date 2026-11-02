#pragma force_active on

extern "C" char lbl_80487178[];

class Class_802A3938 {
public:
    void* vtable;
    char c;
    int value;
    ~Class_802A3938() {}
};

extern "C" void fn_802BC8D0(void* a, void* b, void* c, void* d, void* e);

extern "C" void fn_802BD278(void* a, void* b, void* c, void* d, int e) {
    Class_802A3938 local0;
    local0.value = e;
    local0.c = 0;
    local0.vtable = lbl_80487178;
    fn_802BC8D0(a, c, b, d, &local0);
}
