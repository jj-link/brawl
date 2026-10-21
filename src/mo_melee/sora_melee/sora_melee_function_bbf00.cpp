#include <types.h>
#pragma force_active on

struct fn27Elem {
    s32 id;
    void* unk4;
};

struct fn27Sub {
    virtual void vf0();
    virtual fn27Elem* get(s32 index);
    virtual void vf2();
    virtual s32 count();
};

struct fn27Owner {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void slot60(void* p, f32 f);
    u8 pad[0x3c];
    fn27Sub* m_sub;
};

extern "C" void fn_27_BBF00(fn27Owner* self, s32 id, f32 f) {
    s32 i = self->m_sub->count() - 1;
    for (; i >= 0; i--) {
        fn27Elem* e = self->m_sub->get(i);
        if (id == e->id) {
            self->slot60(self->m_sub->get(i)->unk4, f);
        }
    }
}
