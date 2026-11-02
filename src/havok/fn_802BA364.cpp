#pragma force_active on
extern "C" void fn_802B9B8C(void*, void*, void*, void*, void*);
extern "C" char lbl_80487178[];

class Class_802A3938 {
public:
    void* vtable;
    char b;
    int x;
    ~Class_802A3938() {}
};

extern "C" void fn_802BA364(void* a, void* b, void* c, void* d, int e) {
    Class_802A3938 local0;
    local0.x = e;
    local0.b = 0;
    local0.vtable = lbl_80487178;
    fn_802B9B8C(a, c, b, d, &local0);
}
