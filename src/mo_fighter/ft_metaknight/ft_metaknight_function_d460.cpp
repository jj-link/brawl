#include <mt/mt_vector.h>
#include <types.h>
#pragma force_active on

extern "C" Vec3f fn_27_8CA78(void* object);
extern "C" int fn_27_14D680(void* object, int value);

class FtMetaKnightChildTarget {
public:
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void callTarget(s32 index, Vec3f* position, s32 a, s32 b, s32 c) = 0;
};

extern "C" void fn_111_D460(void* unused, void* object, s32 index, void* owner) {
    Vec3f position = fn_27_8CA78(object);
    int value = fn_27_14D680(object, 1);
    void* child = *reinterpret_cast<void**>(reinterpret_cast<u8*>(owner) + 0xD8);
    FtMetaKnightChildTarget* target = *reinterpret_cast<FtMetaKnightChildTarget**>(reinterpret_cast<u8*>(child) + 0x1C);
    target->callTarget(index, &position, *reinterpret_cast<s32*>(reinterpret_cast<u8*>(object) + 0x28), 0, value);
}
