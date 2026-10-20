#include <types.h>
#pragma force_active on

extern "C" bool isEnd__9soAnimChrCFv(void* self);

class soAnimSource {
public:
    virtual void v0();
    virtual void* get(void* arg);
};

extern "C" bool fn_27_17584(u8* self, void* arg) {
    soAnimSource* src = *reinterpret_cast<soAnimSource**>(self + 0x8c);
    s32* p = static_cast<s32*>(src->get(arg));
    if (*p == 0) {
        return false;
    }
    src = *reinterpret_cast<soAnimSource**>(self + 0x8c);
    void* q = src->get(arg);
    return isEnd__9soAnimChrCFv(q);
}
