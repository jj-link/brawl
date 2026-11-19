#pragma force_active on
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
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
    virtual void s37(int, int, int);
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
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80(void*);
};
struct Stage { char pad[0x1a0]; int f1a0; };
struct Adv { unsigned char pad0[0x5FD]; unsigned char cur; unsigned char pad1[0x4916-0x5FE]; unsigned char prev; };
struct GGlobal { char pad[0x30]; Adv* adv; };
struct Cb { int a; void* vt; int c; Stage* st; Ground* g1; Ground* g2; void* d; char e; };
extern "C" {
extern GGlobal* g_GameGlobal;
extern void* g_stTriggerMng;
extern char lbl_40_data_0[];
extern char lbl_40_data_21D0[];
int createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(void*, int, void*);
Ground* create__19grGimmickMotionPathFiPCcPCc(short, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_27_233F58(int, void*);

inline Ground* helper(Stage* stage, char* d) {
    int trig;
    Ground* g2 = 0;
    Ground* g1;
    int has = 0;
    char* data = lbl_40_data_0;
    trig = createTrigger__12stTriggerMngFQ27Gimmick8AreaKindP13stTriggerData(g_stTriggerMng, 10, d + 12);
    g1 = create__19grGimmickMotionPathFiPCcPCc((short)((unsigned char*)d)[6], data + 0x274, data + 0x284);
    addGround__5StageFP6Ground(stage, g1);
    if (((unsigned char*)d)[7]) has = 1;
    if (has) {
        g2 = create__19grGimmickMotionPathFiPCcPCc(((unsigned char*)d)[7], data + 0x274, data + 0x29c);
        addGround__5StageFP6Ground(stage, g2);
    }
    Adv* a = g_GameGlobal->adv;
    int cur = a->cur;
    int v = cur - a->prev;
    int lo = cur - 5;
    if (v < lo) v = lo;
    if (v < 0) v = 0;
    if (v > 14) v = 14;
    *(float*)d = *(float*)(d + (((unsigned)v << 2) & 0x3fc) + 0x14);
    g1->s80(d);
    g1->s37(stage->f1a0, 0, 0);
    if (has) {
        g2->s80(d);
        g2->s37(stage->f1a0, 0, 0);
    }
    Cb* c = (Cb*)__nw__FUlQ25Heaps8HeapType(0x24, 15);
    if (c) {
        c->a = 0;
        c->c = 0x15;
        c->vt = lbl_40_data_21D0;
        c->st = stage;
        c->g1 = g1;
        c->g2 = g2;
        c->d = d;
        c->e = 0;
    }
    fn_27_233F58(trig, c);
    return g1;
}
Ground* fn_40_4828(Stage* stage, char* d) { return helper(stage, d); }
}
