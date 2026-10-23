#pragma force_active on
class Obj {
public:
    virtual ~Obj();
    virtual void m1(void*, void*);
};

extern "C" void fn_802C0A08(void* a, void* b, void* c, void* d) {
    ((Obj*)d)->m1(a, b);
}
