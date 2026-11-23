#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#pragma force_active on

extern "C" void fn_800B8EDC(void*, void*);
extern "C" void fn_800B8A0C(void*, int);

struct Base {
    char pad[0x5c];
};

struct Entry : Base {
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

extern "C" void fn_800F5284(char* self) {
    clearG3d(*(nw4r::g3d::G3dObj**)(self + 0xe4), Ptr<nw4r::g3d::G3dObj>(0));

    if (*(void**)(self + 0xe8) != 0) {
        fn_800B8EDC(*(void**)(self + 0xe8), *(void**)(self + 0x9c));
        fn_800B8A0C(*(void**)(self + 0xe8), 1);
        *(void**)(self + 0xe8) = 0;
    }

    char* q = self;
    for (int i = 0; i < 9; i++) {
        Entry* p = *(Entry**)(q + 0x9c);
        if (p != 0) {
            if (p != 0) {
                p->destroy(1);
            }
            *(Entry**)(q + 0x9c) = 0;
            *(char*)(q + 0xa0) = 0;
        }
        q += 8;
    }
}
