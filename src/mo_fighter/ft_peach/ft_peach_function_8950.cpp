#include <types.h>
#pragma force_active on

extern "C" void* fn_103_8450(void*, s32, s32, s32, s32, s32, s32);

struct PeachMember {
    u32 padding[2];
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void initialize();
};

extern "C" void* fn_103_8950(void* object) {
    u8* p = static_cast<u8*>(object);
    fn_103_8450(p + 0x1C0, reinterpret_cast<s32>(object), 0x4D,
                reinterpret_cast<s32>(p + 0x134), 0x20,
                reinterpret_cast<s32>(p + 0x1B4), 3);
    reinterpret_cast<PeachMember*>(p + 0x1C0)->initialize();
    return object;
}
