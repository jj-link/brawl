#include <types.h>
#pragma force_active on

struct ViewerData {
    u8 pad0[0x190];
    void* field190;
    u8 pad194[0x1C7C - 0x194];
    void* message;
};

struct ViewerBase {
    u8 pad0[0x3C];
};

class Viewer : public ViewerBase {
public:
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
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42(void*, ViewerData*);
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79(s32);
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();

    u8 pad40[0x1AC - 0x40];
    ViewerData* data;
};

extern "C" {
void printIndex__5MuMsgFUlUlPv(void*, u32, u32, void*);
void playSE__9sndSystemF5SndIDiiii(void*, s32, s32, s32, s32, s32);
extern void* g_sndSystem;

void fn_6_61FC(Viewer* self, s32 arg1) {
    self->vf42(self->data->field190, self->data);
    self->vf85();
    printIndex__5MuMsgFUlUlPv(self->data->message, 0xC, 0, 0);
    self->vf79(arg1);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 5, -1, 0, 0, -1);
}
}
