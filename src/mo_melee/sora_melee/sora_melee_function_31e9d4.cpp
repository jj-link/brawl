#pragma force_active on
extern "C" int fn_27_321F80(void* a0, void* p1, void* self, void* p3, void* p4, void* p5, void* p6);

struct Vt {
    virtual void* f0();
    virtual void* f1();
    virtual Vt* f2();
};

extern "C" int fn_27_31E9D4(void* a0, void* p1, void* self, void* p3, void* p4, void* p5, void* p6) {
    Vt* obj = *(Vt**)(*(char**)((char*)self + 0xD8) + 0x18);
    void* r31 = *(void**)(*(char**)((char*)self + 0x8) + 0x28);
    Vt* t = obj->f2();
    void* r9 = t->f2();
    fn_27_321F80(p1, r31, p3, p4, p5, p6, r9);
    return 1;
}
