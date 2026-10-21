#include <types.h>
#pragma force_active on

class Inner {
public:
    virtual void vf0() = 0;
    virtual void* get(s32 index) = 0;
    virtual void vf2() = 0;
    virtual s32 count() = 0;
};

class Sink {
public:
    virtual void vf0() = 0;
    virtual void vf1() = 0;
    virtual void vf2() = 0;
    virtual void vf3() = 0;
    virtual void vf4() = 0;
    virtual void vf5() = 0;
    virtual void vf6() = 0;
    virtual void vf7() = 0;
    virtual void vf8() = 0;
    virtual void vf9() = 0;
    virtual void apply(void** p) = 0;
};

extern "C" void fn_27_FDFB0(short* a, const char* b);

extern "C" {
void fn_27_1CAA3C(u8* self, s16* filter, Sink* sink) {
    s16 sp8;
    void* spC;
    s32 count = ((Inner*)(self + 0x10))->count();
    for (s32 i = 0; i < count; i++) {
        void* item = ((Inner*)(self + 0x10))->get(i);
        fn_27_FDFB0(&sp8, (const char*)item);
        if (sp8 & *filter) {
            spC = ((Inner*)(self + 0x10))->get(i);
            sink->apply(&spC);
        }
    }
}
}
