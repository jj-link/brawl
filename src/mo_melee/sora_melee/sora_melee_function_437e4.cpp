#pragma force_active on
class SubObj {
public:
    virtual void vf0();
    virtual void* vf1(void* c);
    virtual void vf2();
    virtual void* vf3();
};

extern "C" void fn_27_420D4(void* a, void* b, void* c, void* d);

extern "C" void fn_27_437E4(char* self, void* a, void* b, void* c) {
    SubObj* sub = *(SubObj**)(self + 0x58);
    void* r = sub->vf1(c);
    fn_27_420D4(r, *(void**)(self + 0x30), a, b);
}
