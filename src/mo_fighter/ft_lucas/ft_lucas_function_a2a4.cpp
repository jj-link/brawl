#include <types.h>
#pragma force_active on

struct LucasObjectWords {
    u32 w[9];
};

extern "C" LucasObjectWords* fn_114_9DA4(
    LucasObjectWords*, u32, u32, u32, u32, u32, u32);

struct LucasInterfacePrefix {
    u32 words[2];
};

class LucasEmbeddedInterface : public LucasInterfacePrefix {
public:
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
    virtual void activate();
};

extern "C" void* fn_114_A2A4(void* object) {
    char* self = static_cast<char*>(object);
    fn_114_9DA4(
        reinterpret_cast<LucasObjectWords*>(self + 0x1c0),
        (u32)object,
        0x4d,
        (u32)(self + 0x134),
        0x20,
        (u32)(self + 0x1b4),
        3);
    reinterpret_cast<LucasEmbeddedInterface*>(self + 0x1c0)->activate();
    return object;
}
