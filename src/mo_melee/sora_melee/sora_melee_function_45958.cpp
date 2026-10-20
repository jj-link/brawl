#pragma force_active on
class Inner {
public:
    virtual void f0();
    virtual void* f3(void* p);
};

class Outer {
public:
    char pad[0x58];
    Inner* m_inner;
};

extern "C" void fn_27_42A54(void* self, void* a, void* b, void* c);

extern "C" void fn_27_45958(void* self, Outer* obj, void* p5, void* p6) {
    void* r = obj->m_inner->f3(p6);
    fn_27_42A54(self, r, (char*)obj + 0x38, p5);
}
