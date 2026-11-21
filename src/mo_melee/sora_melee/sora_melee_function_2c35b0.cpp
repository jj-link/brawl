#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
extern "C" void fn_800B8EDC(void*, void*);
extern "C" void fn_800B8A0C(void*, int);
struct Base { char pad[0x5c]; };
struct Entry : Base { virtual ~Entry(); };
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
inline void clearEntry(Entry*& object, Ptr<Entry> replacement) {
    if (object) {
        delete object;
        object = replacement.p;
    }
}
#pragma force_active on
extern "C" void fn_27_2C35B0(void* arg0) {
    char* self = (char*)arg0;
    void* p5c = *(void**)(self + 0x5c);
    clearG3d(*(nw4r::g3d::G3dObj**)(self + 0x58), Ptr<nw4r::g3d::G3dObj>(0));
    fn_800B8EDC(p5c, *(void**)(self + 0x54));
    fn_800B8A0C(p5c, 1);
    clearEntry(*(Entry**)(self + 0x54), Ptr<Entry>(0));
}