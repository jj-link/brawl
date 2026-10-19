#include <types.h>
#pragma force_active on

extern "C" void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);

extern "C" unsigned char g_ftCommonDataAccesser[];

// The virtual target object reached via object->0xd8 -> 0x64.
// Slot 5 takes (int, int) and returns a pointer.
class LucasVirtual {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void* v5(int, int);
};

class LucasSelf {
public:
    void* fn_114_10DE4(void* object) {
        void* p = *(void**)((char*)object + 0xd8);
        void* target = *(void**)((char*)p + 0x64);
        (void)getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 0x1a);
        return reinterpret_cast<LucasVirtual*>(target)->v5(1, 0x20000003);
    }
};

extern "C" void* fn_114_10DE4(void* self, void* object) {
    return reinterpret_cast<LucasSelf*>(self)->fn_114_10DE4(object);
}
