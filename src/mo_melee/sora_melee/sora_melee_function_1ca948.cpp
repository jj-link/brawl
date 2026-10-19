#pragma force_active on
class stObj {
public:
    virtual void f0();
    virtual stObj* f3(void* p);
};

extern "C" {
void fn_27_1CA948(stObj* self, void** src, void* arg) {
    stObj* r = self->f3(arg);
    *(void**)r = *src;
}
}
