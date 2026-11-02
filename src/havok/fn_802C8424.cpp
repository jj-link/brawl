#pragma force_active on

extern "C" void fn_802C7288(void*, void*, void*, void*, void*);
extern "C" char lbl_80487198[];
extern "C" const float lbl_805A3FEC;

struct Vtable_Class_802A38DC {
    void* vtable;
};

class Class_802A38DC : public Vtable_Class_802A38DC {
public:
    float f;
    void* p;
    
    Class_802A38DC() : f(lbl_805A3FEC) {}
    ~Class_802A38DC() {}
};

extern "C" void fn_802C8424(void* a, void* b, void* c, void* d, void* e) {
    Class_802A38DC local0;
    local0.p = e;
    local0.vtable = lbl_80487198;
    fn_802C7288(a, c, b, d, &local0);
}
