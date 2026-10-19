#include <types.h>
#pragma force_active on

class IObj {
public:
    virtual void* a();
    virtual void* b();
    virtual void* c();
    virtual void* d();
    virtual void* e();
    virtual void* f();
    virtual void* g();
    virtual void* h();
    virtual void* i();
    virtual void* j();
    virtual void* k();
    virtual void* l();
    virtual void* m();
    virtual void* get(void* arg);
};

extern "C" void fn_2_2EC68(void* self) {
    for (u32 i = 0; i < 3; i++) {
        void* arr = *(void**)((char*)self + 0x64C);
        IObj* obj = *(IObj**)((char*)self + 0x654);
        void* p = *(void**)((char*)arr + i * 4 + 0x33C);
        void* arg = *(void**)((char*)p + 0x10);
        obj->get(arg);
    }
}
