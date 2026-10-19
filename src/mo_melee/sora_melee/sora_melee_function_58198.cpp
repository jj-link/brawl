#pragma force_active on
class Bar {
public:
    virtual ~Bar() { }
    void* m_ptr;
};

class Obj {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual Bar* v3(void* a, void* b, void* c) = 0;
};

extern "C" void fn_8007979C(void* a, void* b, void* c, void* d);

extern "C" void fn_27_58198(Obj* obj, void* a, void* b, void* c) {
    Bar* result = obj->v3(a, b, c);
    if (result->m_ptr) {
        fn_8007979C(result->m_ptr, c, b, 0);
    }
}
