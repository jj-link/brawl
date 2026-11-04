#include <types.h>
#pragma force_active on

class efScreenHandle {
public:
    unsigned long isValid() const;
};

class fn27ScreenA {
public:
    virtual void vf0();
    virtual efScreenHandle* getHandle();
};

class fn27ScreenB {
public:
    virtual void vf0();
    virtual signed char* getByte(unsigned long idx);
};

extern "C" {
void fn_8005E3C8(void*, const unsigned char*, float);
extern void* g_efScreen;
}

extern "C" void fn_27_9FEB0(fn27ScreenA** self, unsigned long a, int b) {
    efScreenHandle* h = (*self)->getHandle();
    if (h->isValid() == 1) {
        signed char* p = ((fn27ScreenB*)*self)->getByte(a);
        unsigned char v = *p;
        fn_8005E3C8(g_efScreen, &v, (float)b);
        signed char* q = ((fn27ScreenB*)*self)->getByte(a);
        *q = -1;
    }
}
