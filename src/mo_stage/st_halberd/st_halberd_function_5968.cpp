#pragma force_active on
extern "C" void update__9grGimmickFf(void* self, float deltaFrame);
extern "C" const float lbl_57_rodata_1A0;

struct grGimmickVirtBase {
    char pad[0x3c];
};

struct grGimmickVirt : public grGimmickVirtBase {
    virtual void vf0(void); virtual void vf1(void); virtual void vf2(void); virtual void vf3(void); virtual void vf4(void); virtual void vf5(void); virtual void vf6(void); virtual void vf7(void); virtual void vf8(void); virtual void vf9(void);
    virtual void vf10(void); virtual void vf11(void); virtual void vf12(void); virtual void vf13(void); virtual void vf14(void); virtual void vf15(void); virtual void vf16(void); virtual void vf17(void); virtual void vf18(void); virtual void vf19(void);
    virtual void vf20(void); virtual void vf21(void); virtual void vf22(void); virtual void vf23(void); virtual void vf24(void); virtual void vf25(void); virtual void vf26(void); virtual void vf27(void); virtual void vf28(void); virtual void vf29(void);
    virtual void vf30(void); virtual void vf31(void); virtual void vf32(void); virtual void vf33(void); virtual void vf34(void); virtual void vf35(void); virtual void vf36(void); virtual void vf37(void); virtual void vf38(void); virtual void vf39(void);
    virtual void vf40(void); virtual void vf41(void); virtual void vf42(void); virtual void vf43(void); virtual void vf44(void); virtual void vf45(void); virtual void vf46(void); virtual void vf47(void);
    virtual void vf48(void* p, int flag, int val);
    virtual void vf49(void);
    virtual void vf50(void); virtual void vf51(void); virtual void vf52(void); virtual void vf53(void); virtual void vf54(void); virtual void vf55(void); virtual void vf56(void); virtual void vf57(void); virtual void vf58(void); virtual void vf59(void);
    virtual void vf60(void); virtual void vf61(void); virtual void vf62(void); virtual void vf63(void); virtual void vf64(void); virtual void vf65(void); virtual void vf66(void); virtual void vf67(void); virtual void vf68(void); virtual void vf69(void);
    virtual void vf70(void); virtual void vf71(void); virtual void vf72(void); virtual void vf73(void); virtual void vf74(void); virtual void vf75(void); virtual void vf76(void); virtual void vf77(void); virtual void vf78(void); virtual void vf79(void);
    virtual void vf80(void); virtual void vf81(void); virtual void vf82(void); virtual void vf83(void); virtual void vf84(void); virtual void vf85(void); virtual void vf86(void); virtual void vf87(void); virtual void vf88(void); virtual void vf89(void);
    virtual void vf90(void); virtual void vf91(void); virtual void vf92(void); virtual void vf93(void); virtual void vf94(void); virtual void vf95(void); virtual void vf96(void); virtual void vf97(void); virtual void vf98(void); virtual void vf99(void);
    virtual void vf100(void); virtual void vf101(void); virtual void vf102(void); virtual void vf103(void); virtual void vf104(void); virtual void vf105(void); virtual void vf106(void); virtual void vf107(void); virtual void vf108(void); virtual void vf109(void);
    virtual void vf110(void); virtual void vf111(void); virtual void vf112(void); virtual void vf113(void);
    virtual void vf114(float f); virtual void vf115(float f); virtual void vf116(float f); virtual void vf117(float f);
};

extern "C" void fn_57_5968(void* self, float deltaFrame) {
    update__9grGimmickFf(self, deltaFrame);
    if (*((unsigned char*)self + 0xc8) != 0) {
        ((grGimmickVirt*)self)->vf114(deltaFrame);
        ((grGimmickVirt*)self)->vf115(deltaFrame);
        ((grGimmickVirt*)self)->vf116(deltaFrame);
        ((grGimmickVirt*)self)->vf117(deltaFrame);
        ((grGimmickVirt*)self)->vf71();
        *((unsigned char*)self + 0x6c) &= ~0x2;
        switch (*(signed char*)*(char**)((char*)self + 0x15c)) {
        case 2:
            if (*(float*)*(char**)((char*)self + 0x158) < lbl_57_rodata_1A0) {
                if (*(char**)((char*)self + 0x168) != 0) {
                    ((grGimmickVirt*)self)->vf48(*(char**)((char*)self + 0x168), 0, *(int*)((char*)self + 0x17c));
                    ((grGimmickVirt*)self)->vf48(*(char**)((char*)self + 0x168) + 0xc, 0, *(int*)((char*)self + 0x180));
                    ((grGimmickVirt*)self)->vf48(*(char**)((char*)self + 0x168) + 0x18, 0, *(int*)((char*)self + 0x184));
                    ((grGimmickVirt*)self)->vf48(*(char**)((char*)self + 0x168) + 0x24, 0, *(int*)((char*)self + 0x188));
                }
            }
            break;
        }
    }
}
