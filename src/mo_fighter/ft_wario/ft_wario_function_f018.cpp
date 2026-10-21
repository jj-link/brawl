#pragma force_active on
#define DUMMY(n) virtual void d##n();

extern float lbl_110_rodata_74;

class WorkModule {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4)
    virtual void v7(int, unsigned int);
    DUMMY(5) DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9) DUMMY(10) DUMMY(11)
    DUMMY(12) DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17)
    virtual void setFlag(unsigned int);
};

class VObj50 {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4) DUMMY(5) DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9)
    DUMMY(10) DUMMY(11) DUMMY(12) DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18) DUMMY(19)
    DUMMY(20) DUMMY(21) DUMMY(22) DUMMY(23) DUMMY(24) DUMMY(25) DUMMY(26) DUMMY(27) DUMMY(28) DUMMY(29)
    DUMMY(30) DUMMY(31) DUMMY(32) DUMMY(33) DUMMY(34) DUMMY(35) DUMMY(36) DUMMY(37) DUMMY(38) DUMMY(39)
    DUMMY(40) DUMMY(41) DUMMY(42) DUMMY(43) DUMMY(44) DUMMY(45) DUMMY(46) DUMMY(47)
    virtual void v50(float);
};

class SubModule {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4) DUMMY(5) DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9)
    DUMMY(10) DUMMY(11) DUMMY(12) DUMMY(13) DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18) DUMMY(19)
    DUMMY(20) DUMMY(21) DUMMY(22) DUMMY(23) DUMMY(24) DUMMY(25) DUMMY(26) DUMMY(27) DUMMY(28) DUMMY(29)
    DUMMY(30) DUMMY(31) DUMMY(32) DUMMY(33) DUMMY(34) DUMMY(35) DUMMY(36) DUMMY(37) DUMMY(38)
    virtual void fnA4(int);
};

struct Modules {
    char pad0[0x1C];
    VObj50* a;
    char pad1[0x64 - 0x20];
    WorkModule* b;
    char pad2[0x88 - 0x68];
    SubModule* sub;
};

struct Accesser {
    char pad[0xD8];
    Modules* modules;
};

extern "C" {
void fn_110_F018(void* unused, Accesser* p) {
    Modules* m = p->modules;
    VObj50* a = m->a;
    WorkModule* b = m->b;
    b->v7(0, 0x10000041);
    b->v7(0, 0x10000042);
    a->v50(lbl_110_rodata_74);
    b->setFlag(0x1200003F);
    p->modules->sub->fnA4(0x27);
}
}
