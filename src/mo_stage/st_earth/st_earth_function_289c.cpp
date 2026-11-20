#pragma force_active on
#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>

struct StageCheck {
    char pad[0x38];
    f32 threshold;
    u8 count;
};

struct StageEntry {
    u8 type;
    char pad[0x13];
    Vec3f pos;
};

struct Stage {
    char pad0[0x9C];
    StageCheck* unk9C;
    char pad1[0x278 - 0xA0];
    StageEntry* unk278;
};

struct Ground {
    char pad[0x3C];
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
    virtual void vf42();
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
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual void vf109();
    virtual void vf110();
    virtual void vf111();
    virtual void vf112();
    virtual void vf113();
    virtual void slot114(Vec3f* out, f32 f);
};

extern "C" Ground* getGround__5StageFi(Stage* self, int index);

extern "C" s32 fn_66_289C(Stage* self, f32 farg0) {
    Vec3f sp14;
    if (self->unk278 == NULL) {
        return 0;
    }
    Ground* ground = getGround__5StageFi(self, 3);
    if (ground == NULL) {
        return 0;
    }
    StageCheck* chk = self->unk9C;
    if (chk == NULL) {
        return 0;
    }
    ground->slot114(&sp14, farg0);
    u8 i = 0;
    u32 count = chk->count;
    for (; i != count; i++) {
        StageEntry* e = (StageEntry*)((char*)self->unk278 + i * 0x58);
        if (e->type == 3) {
            Vec3f p;
            p = e->pos;
            if ((f32)nw4r::math::FAbs(sp14.m_x - p.m_x) < chk->threshold) {
                return 0;
            }
        }
    }
    return 1;
}
