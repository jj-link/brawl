#include <types.h>
#pragma force_active on

class Member {
public:
    virtual void vf0() = 0;
    virtual void* vf1(s32 idx) = 0;
    virtual void vf2() = 0;
    virtual s32 vf3() = 0;
};

class Visitor {
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
    virtual void vf10(s32* p) = 0;
};

extern "C" void fn_27_FE050(s16* a, s16* b);

extern "C" {
void fn_27_1BA914(u8* self, s16* mask, Visitor* visitor) {
    s32 count = ((Member*)(self + 0x10))->vf3();
    for (s32 i = 0; i < count; i++) {
        void* item = ((Member*)(self + 0x10))->vf1(i);
        s16 sp8;
        fn_27_FE050(&sp8, (s16*)item);
        if (sp8 & *mask) {
            s32 val = (s32)((Member*)(self + 0x10))->vf1(i);
            visitor->vf10(&val);
        }
    }
}
}
