#pragma force_active on

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(int, char*);
    virtual void v4();
    virtual void v5();
    virtual void v6(int, bool);
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12(int, int, int);
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual int v17(int);
    virtual void v18(int);
};

struct MotionBase {
    char pad[8];
};

class Motion : public MotionBase {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual unsigned int get(int);
};

extern "C" void fn_123_134C4(char* self) {
    VObj* a = *(VObj**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x64);
    if (a->v17(0x12000003) == 0) {
        Motion* b = *(Motion**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x10);
        if (b->get(0) == 1U) {
            VObj* c = *(VObj**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x14);
            c->v6(0, false);

            VObj* d = *(VObj**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x64);
            d->v18(0x22000000);

            VObj* e = *(VObj**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x90);
            e->v12(0, 1, -1);
            return;
        }
    }

    char* modules = *(char**)(self + 0x60);
    VObj* f = *(VObj**)(*(char**)(modules + 0xD8) + 0x70);
    f->v3(1, modules);
}
