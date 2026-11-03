#include <types.h>
#pragma force_active on

struct FlagPair {
    u32 flags;
    s32 value;
};

class FlagSource {
public:
    virtual void slot00();
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
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
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual FlagPair* get(FlagPair* out);
};

extern "C" void fn_8019CF5C(s32* arg0, FlagSource* src) {
    FlagPair sp8;
    FlagPair* p = src->get(&sp8);
    u32 flags = p->flags;
    s32 value = p->value;
    if (!(flags & 1)) {
        value |= ~0xFF;
    }
    if (!(flags & 2)) {
        value |= 0xFF;
    }
    *arg0 = value;
}
