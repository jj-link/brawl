#include <mt/mt_vector.h>
#pragma force_active on

struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};

struct ModuleA {
    int a, b;
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(int, int);
    virtual void p43(); virtual void p44(); virtual void p45(); virtual void p46();
    virtual void p47(); virtual void p48(); virtual void p49(); virtual void p50();
    virtual void p51(); virtual void p52(); virtual void p53(); virtual void p54();
    virtual void p55(); virtual void p56(); virtual void p57(); virtual void p58();
    virtual void p59(); virtual void p60(); virtual void p61(); virtual void p62();
    virtual void p63(); virtual void p64(); virtual void p65(); virtual void p66();
    virtual void p67(); virtual void p68(); virtual void p69(); virtual void p70();
    virtual void p71(); virtual void p72(); virtual void p73(); virtual void p74();
    virtual void p75(); virtual void p76(); virtual void p77(); virtual void p78();
    virtual void p79(); virtual void p80(); virtual void p81(); virtual void p82();
    virtual void p83(); virtual void p84(); virtual void p85(); virtual void p86();
    virtual void p87(); virtual void p88(); virtual void p89(); virtual void p90();
    virtual void p91(); virtual void p92(); virtual void p93(); virtual void p94();
    virtual void p95(); virtual void p96(); virtual void p97(); virtual void p98();
    virtual void p99(); virtual void p100(); virtual void p101(); virtual void p102();
    virtual void p103(); virtual void p104(int, void*, float);
};

struct ModuleB {
    virtual void q00(); virtual void q01(); virtual void q02(); virtual void q03();
    virtual void q04(); virtual void q05(); virtual void q06(); virtual void q07();
    virtual void q08(); virtual void q09(); virtual void q10(); virtual void q11();
    virtual void q12(); virtual void q13(); virtual void q14(); virtual void q15();
    virtual void q16(); virtual void q17(); virtual void q18(); virtual void q19();
    virtual void q20(); virtual void q21(); virtual void q22(); virtual void q23();
    virtual void q24(); virtual void q25(); virtual void q26(); virtual void q27();
    virtual void q28(); virtual void q29(); virtual void q30(); virtual void q31();
    virtual void q32(); virtual void q33(); virtual void q34(); virtual void q35();
    virtual void q36(); virtual void q37(); virtual void q38(); virtual void q39();
    virtual void q40(); virtual void q41(); virtual void q42(); virtual void q43();
    virtual void q44(); virtual void q45(); virtual void q46(); virtual void q47();
    virtual void q48(); virtual void q49(); virtual void q50(); virtual void q51();
    virtual void q52(); virtual void q53(); virtual void q54(); virtual void q55();
    virtual void q56(); virtual void q57(); virtual void q58(); virtual void q59();
    virtual void q60(); virtual void q61(); virtual void q62(); virtual void q63();
    virtual void q64(); virtual void q65(); virtual void q66(); virtual void q67();
    virtual void q68(); virtual void q69(); virtual void q70(); virtual void q71();
    virtual void q72(); virtual void q73(); virtual void q74(); virtual void q75();
    virtual void q76(); virtual void q77(); virtual void q78(); virtual void q79();
    virtual void q80(); virtual void q81(); virtual void q82(); virtual void q83();
    virtual void q84(); virtual void q85(); virtual void q86(); virtual void q87();
    virtual void q88(); virtual void q89(); virtual void q90(); virtual void q91();
    virtual void q92(); virtual void q93(); virtual void q94(); virtual void q95();
    virtual void q96(); virtual void q97(); virtual void q98(); virtual void q99(int, int, int);
};

struct ModuleC {
    virtual void r00(); virtual void r01(); virtual void r02(); virtual void r03();
    virtual void r04(); virtual void r05(); virtual void r06(); virtual void r07();
    virtual void r08(); virtual void r09(); virtual void r10(); virtual void r11();
    virtual void r12(); virtual void r13(); virtual void r14(); virtual void r15();
    virtual void r16(); virtual void r17(); virtual void r18(); virtual void r19();
    virtual void r20(); virtual void r21(); virtual void r22(); virtual void r23();
    virtual void r24(); virtual void r25(); virtual void r26(); virtual void r27();
    virtual void r28(); virtual void r29(); virtual void r30(); virtual void r31();
    virtual void r32(); virtual void r33(); virtual void r34(int, void*);
};

extern "C" {
extern const float lbl_27_rodata_7A14;
void fn_27_1D8370(void*, const Param*);
void* __memcpy(void*, const void*, unsigned long);

void fn_27_35F3C8(void* obj, int resource, int team, int parameter) {
    char* o = (char*)obj;
    int variant = *(int*)((char*)(*(void**)(o + 0x1f84)) + 0x24);
    Param p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;

    Vec3f position;
    position.m_x = lbl_27_rodata_7A14;
    position.m_y = lbl_27_rodata_7A14;
    position.m_z = lbl_27_rodata_7A14;
    __memcpy(&p.position, &position, sizeof(Vec3f));

    p.facing = lbl_27_rodata_7A14;
    p.parameter = parameter;
    p.variant = variant;
    p.situation = 2;
    p.status = 0x80;
    p.reserved2 = 0;
    p.motion = 0x35f;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;

    fn_27_1D8370(obj, &p);

    ModuleA* m1 = (ModuleA*)*(void**)((char*)*(void**)((char*)*(void**)(o + 0x60) + 0xd8) + 0x10);
    m1->p42(1, 0);

    ModuleB* m2 = (ModuleB*)*(void**)((char*)*(void**)((char*)*(void**)(o + 0x60) + 0xd8) + 0x54);
    m2->q99(3, 4, 1);

    ModuleC* m3 = (ModuleC*)*(void**)((char*)*(void**)((char*)*(void**)(o + 0x60) + 0xd8) + 0x70);
    m3->r34(0, *(void**)(o + 0x60));

    ModuleA* m4 = (ModuleA*)*(void**)((char*)*(void**)((char*)*(void**)(o + 0x60) + 0xd8) + 0x10);
    m4->p104(0, *(void**)((char*)*(void**)(o + 0x60) + 0xd8), *(float*)((char*)(*(void**)(o + 0x1f84)) + 0x20));
}
}