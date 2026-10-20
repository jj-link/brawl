#include <types.h>
#pragma force_active on

struct ftManager;
extern ftManager* g_ftManager;

extern "C" int getPlayerNo__9ftManagerFi(ftManager*, int);
extern "C" u32 fn_27_27D2AC(void*, s32);

struct TargetBase {
    u8 pad[0x3c];
};

struct Target : TargetBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void notify(u32, int);
};

struct Context {
    u8 pad[0x2c];
    Target* target;
    u8 pad30[4];
    u8 flags;
};

extern "C" void fn_27_2D8EB8(Context* self, int entryId, int value) {
    if ((((u32)self->flags >> 7) & 1) && self->target) {
        u32 player = fn_27_27D2AC(
            self, getPlayerNo__9ftManagerFi(g_ftManager, entryId));
        self->target->notify(player, value);
    }
}
