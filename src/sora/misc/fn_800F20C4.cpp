#pragma force_active on
#include <types.h>
#include <nw4r/g3d/g3d_obj.h>

extern "C" void fn_800B8EDC(void*, void*);
extern "C" void fn_800B8A0C(void*, int);

struct Entry {
    char pad[0x5C];
    virtual void destroy(int);
};

template <class T> struct Ptr {
    T* p;
    Ptr(T* v) : p(v) {}
};

inline void clearG3d(nw4r::g3d::G3dObj*& object, Ptr<nw4r::g3d::G3dObj> replacement) {
    if (object) {
        object->Destroy();
        object = replacement.p;
    }
}

extern "C" void fn_800F20C4(char* self) {
    int i;
    char* q = self;
    void* ctx = *(void**)(q + 0x8C);
    clearG3d(*(nw4r::g3d::G3dObj**)(q + 0x5C), Ptr<nw4r::g3d::G3dObj>(0));
    fn_800B8EDC(ctx, *(void**)(q + 0x48));
    fn_800B8EDC(ctx, *(void**)(q + 0x54));
    fn_800B8EDC(ctx, *(void**)(q + 0x50));
    fn_800B8A0C(ctx, 1);
    for (i = 0; i < 6; i++) {
        Entry* p = *(Entry**)(q + 0x44);
        if (p != 0) {
            if (p != 0) {
                p->destroy(1);
            }
            *(Entry**)(q + 0x44) = 0;
        }
        q += 4;
    }
}
