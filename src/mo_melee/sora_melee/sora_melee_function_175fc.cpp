#include <types.h>
#pragma force_active on

extern "C" bool isLooped__9soAnimChrCFv(void* self);

class soChrA {
public:
    virtual void vf0();
    virtual s32* getState();
};

class soChrB {
public:
    virtual void vf0();
    virtual void* getAnim(void* arg);
};

extern "C" bool fn_27_175FC(u8* self, void* arg) {
    s32* state = ((soChrA*)*(void**)(self + 0x8c))->getState();
    if (*state == 0) {
        return 0;
    }
    void* anim = ((soChrB*)*(void**)(self + 0x8c))->getAnim(arg);
    return isLooped__9soAnimChrCFv(anim);
}
