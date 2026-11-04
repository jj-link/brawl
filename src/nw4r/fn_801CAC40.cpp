#include <revolution/OS/OSMutex.h>
#pragma force_active on
extern "C" {
void fn_8015C238(void*, int);
void __dl__FPv(void*);
}
class SoundObject {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int);
};
extern "C" void* fn_801CAC40(char* self, int flag) {
    if (self != 0) {
        void** cur;
        void** sentinel;
        OSMutex* mutex = (OSMutex*)(self + 0x48);
        OSLockMutex(mutex);
        cur = *(void***)(self + 4);
        sentinel = (void**)(self + 4);
        while (cur != sentinel) {
            void** node = cur;
            cur = (void**)*cur;
            ((SoundObject*)((char*)node - 0xC0))->vf4(0);
        }
        OSUnlockMutex(mutex);
        if (self + 0x18 != 0) {
            fn_8015C238(self + 0x18, 0);
        }
        if (self + 0xC != 0) {
            fn_8015C238(self + 0xC, 0);
        }
        if (self != 0) {
            fn_8015C238(self, 0);
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
