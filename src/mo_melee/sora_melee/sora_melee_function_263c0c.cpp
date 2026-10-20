#include <types.h>
#pragma force_active on

extern float lbl_27_rodata_42C0;

struct Pad {
    char p[0x3c];
};

struct Inner : Pad {
    virtual void vf0(void* p, float f, s32 x);
    virtual void vf1(void* p, float f, s32 x);
    virtual void vf2(void* p, float f, s32 x);
    virtual void vf3(void* p, float f, s32 x);
    virtual void vf4(void* p, float f, s32 x);
    virtual void vf5(void* p, float f, s32 x);
    virtual void vf6(void* p, float f, s32 x);
    virtual void vf7(void* p, float f, s32 x);
    virtual void vf8(void* p, float f, s32 x);
    virtual void vf9(void* p, float f, s32 x);
    virtual void vf10(void* p, float f, s32 x);
    virtual void vf11(void* p, float f, s32 x);
    virtual void vf12(void* p, float f, s32 x);
    virtual void vf13(void* p, float f, s32 x);
    virtual void vf14(void* p, float f, s32 x);
    virtual void vf15(void* p, float f, s32 x);
    virtual void vf16(void* p, float f, s32 x);
    virtual void vf17(void* p, float f, s32 x);
    virtual void vf18(void* p, float f, s32 x);
    virtual void vf19(void* p, float f, s32 x);
    virtual void vf20(void* p, float f, s32 x);
    virtual void vf21(void* p, float f, s32 x);
    virtual void vf22(void* p, float f, s32 x);
    virtual void vf23(void* p, float f, s32 x);
    virtual void vf24(void* p, float f, s32 x);
    virtual void vf25(void* p, float f, s32 x);
    virtual void vf26(void* p, float f, s32 x);
    virtual void vf27(void* p, float f, s32 x);
    virtual void vf28(void* p, float f, s32 x);
    virtual void vf29(void* p, float f, s32 x);
    virtual void vf30(void* p, float f, s32 x);
    virtual void vf31(void* p, float f, s32 x);
    virtual void vf32(void* p, float f, s32 x);
    virtual void vf33(void* p, float f, s32 x);
    virtual void vf34(void* p, float f, s32 x);
    virtual void vf35(void* p, float f, s32 x);
    virtual void vf36(void* p, float f, s32 x);
    virtual void vf37(void* p, float f, s32 x);
    virtual void vf38(void* p, float f, s32 x);
    virtual void vf39(void* p, float f, s32 x);
    virtual void vf40(void* p, float f, s32 x);
    virtual void vf41(void* p, float f, s32 x);
    virtual void vf42(void* p, float f, s32 x);
    virtual void vf43(void* p, float f, s32 x);
    virtual void vf44(void* p, float f, s32 x);
    virtual void vf45(void* p, float f, s32 x);
    virtual void vf46(void* p, float f, s32 x);
    virtual void vf47(void* p, float f, s32 x);
    virtual void vf48(void* p, float f, s32 x);
    virtual void vf49(void* p, float f, s32 x);
    virtual void vf50(void* p, float f, s32 x);
    virtual void vf51(void* p, float f, s32 x);
    virtual void vf52(void* p, float f, s32 x);
    virtual void vf53(void* p, float f, s32 x);
    virtual void vf54(void* p, float f, s32 x);
    virtual void vf55(void* p, float f, s32 x);
    virtual void vf56(void* p, float f, s32 x);
    virtual void vf57(void* p, float f, s32 x);
    virtual void vf58(void* p, float f, s32 x);
    virtual void vf59(void* p, float f, s32 x);
    virtual void vf60(void* p, float f, s32 x);
    virtual void vf61(void* p, float f, s32 x);
    virtual void vf62(void* p, float f, s32 x);
    virtual void vf63(void* p, float f, s32 x);
    virtual void vf64(void* p, float f, s32 x);
    virtual void vf65(void* p, float f, s32 x);
    virtual void vf66(void* p, float f, s32 x);
    virtual void vf67(void* p, float f, s32 x);
    virtual void vf68(void* p, float f, s32 x);
    virtual void vf69(void* p, float f, s32 x);
    virtual void vf70(void* p, float f, s32 x);
    virtual void vf71(void* p, float f, s32 x);
    virtual void vf72(void* p, float f, s32 x);
    virtual void vf73(void* p, float f, s32 x);
    virtual void vf74(void* p, float f, s32 x);
    virtual void vf75(void* p, float f, s32 x);
    virtual void vf76(void* p, float f, s32 x);
    virtual void vf77(void* p, float f, s32 x);
    virtual void vf78(void* p, float f, s32 x);
    virtual void vf79(void* p, float f, s32 x);
    virtual void vf80(void* p, float f, s32 x);
    virtual void vf81(void* p, float f, s32 x);
    virtual void vf82(void* p, float f, s32 x);
    virtual void vf83(void* p, float f, s32 x);
    virtual void vf84(void* p, float f, s32 x);
    virtual void vf85(void* p, float f, s32 x);
    virtual void vf86(void* p, float f, s32 x);
    virtual void vf87(void* p, float f, s32 x);
    virtual void vf88(void* p, float f, s32 x);
    virtual void vf89(void* p, float f, s32 x);
    virtual void vf90(void* p, float f, s32 x);
    virtual void vf91(void* p, float f, s32 x);
    virtual void vf92(void* p, float f, s32 x);
    virtual void vf93(void* p, float f, s32 x);
};

struct Work {
    char pad0[0x70];
    Inner* inner;
    float m_74;
    char m_78[4];
};

extern "C" {
    s32 fn_27_263C0C(Work* self, s32 arg) {
        self->inner->vf91(&self->m_78, self->m_74, arg);
        self->m_74 = lbl_27_rodata_42C0;
        return 0;
    }
}
