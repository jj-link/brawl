#pragma force_active on

struct Vt {
    virtual void* f0();
    virtual void* f1();
    virtual Vt* f2();
};

extern "C" void fn_27_3C97E8(void*, void*, void*, void*, void*, void*, void*);

extern "C" bool fn_27_3C8114(void* a0, void* p1, void* self,
                            void* p3, void* p4, void* p5, void* p6) {
    Vt* obj = *(Vt**)(*(char**)((char*)self + 0xD8) + 0x18);
    void* r31 = *(void**)(*(char**)((char*)self + 0x8) + 0x28);
    Vt* t = obj->f2();
    void* r9 = t->f2();
    fn_27_3C97E8(p1, r31, p3, p4, p5, p6, r9);
    return true;
}
