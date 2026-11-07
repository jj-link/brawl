#pragma force_active on

#define D(n) virtual void d##n();

struct Base8 { char pad[8]; };
struct Base3C { char pad[0x3c]; };

struct M {
    D(0) D(1) D(2)
    virtual void change(int, void*);
    D(4)
    virtual void setInt(int, int);
    D(6) D(7) D(8) D(9) D(10) D(11) D(12) D(13) D(14) D(15)
    virtual int getKind();
    D(17)
    virtual unsigned int isExist(int);
    virtual void onFlag(int);
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
    D(30) D(31) D(32)
    virtual int f33(int);
    virtual int f34(int);
    D(35) D(36) D(37) D(38) D(39)
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47) D(48) D(49)
    D(50) D(51) D(52) D(53) D(54) D(55) D(56) D(57) D(58) D(59)
    D(60) D(61) D(62) D(63) D(64) D(65) D(66) D(67) D(68) D(69)
    D(70) D(71)
    virtual void f72(int, int);
    D(73) D(74)
    virtual void f75(int, int, int, int, int);
    D(76) D(77) D(78) D(79)
    D(80) D(81) D(82) D(83) D(84) D(85) D(86)
    virtual void f87(int);
};

struct M8 : Base8 {
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
    D(30) D(31) D(32)
    virtual int f33(int);
    virtual int f34(int);
    D(35) D(36) D(37) D(38) D(39)
    D(40) D(41) D(42) D(43) D(44) D(45) D(46) D(47) D(48) D(49)
    D(50) D(51) D(52) D(53) D(54) D(55) D(56) D(57) D(58) D(59)
    D(60) D(61) D(62) D(63) D(64) D(65) D(66) D(67) D(68) D(69)
    D(70) D(71)
    virtual void f72(int, int);
};

struct Obj : Base3C {
    D(0) D(1) D(2) D(3) D(4) D(5) D(6) D(7) D(8) D(9)
    D(10) D(11) D(12) D(13) D(14) D(15) D(16) D(17) D(18) D(19)
    D(20) D(21) D(22) D(23) D(24) D(25) D(26) D(27) D(28) D(29)
    D(30) D(31) D(32) D(33) D(34) D(35) D(36) D(37) D(38)
    virtual int a4();
    virtual int a8();
};

struct Modules {
    char pad0[4];
    M8* m4;
    char pad8[8];
    M8* m10;
    char pad14[0x40];
    M* m54;
    char pad58[0xc];
    M* m64;
    char pad68[8];
    M* m70;
    char pad74[0x10];
    M* m84;
};

struct Fighter {
    char pad0[0xd8];
    Modules* modules;
};

struct Self {
    char pad0[0x60];
    Fighter* fighter;
};

struct Event {
    int kind;
    unsigned char b4;
    char pad5[3];
    int v8;
    int vC;
    char pad10[0xc];
    unsigned char b1C;
};

extern "C" int* getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);
extern "C" void fn_27_1324D4(Self*, Event*, Fighter*, Obj*, int);

extern "C" void fn_93_997C(Self* self, Event* ev, Fighter* f, Obj* obj, int val) {
    int kind = ev->kind;
    if (kind >= 0x65) {
        switch (obj->a8()) {
        case 3:
            if (kind == 0x838) {
                switch ((unsigned int)self->fighter->modules->m70->getKind()) {
                case 0: case 1: case 3: case 4: case 5: case 6: case 7: case 8:
                case 10: case 11: case 12: case 13: case 14: case 15: case 17:
                case 18: case 21: case 22: case 23: case 24: {
                    Fighter* ft = self->fighter;
                    ft->modules->m70->change(0x119, ft);
                    ev->b4 = 1;
                    break;
                }
                }
            }
            return;
        case 0x6e:
            switch (kind) {
            case 0x839: {
                Fighter* ft = self->fighter;
                ft->modules->m70->change(0x39, ft);
                return;
            }
            case 0x83a:
                break;
            case 0x83b: {
                f->modules->m64->setInt(*getConstantIndefinite__15soValueAccesserFP16soModuleAccesserUlUl(f, 0xa80e, 0), 0x20000001);
                Fighter* ft = self->fighter;
                ft->modules->m70->change(0x81, ft);
                if (f->modules->m84->isExist(3) == 1) {
                    f->modules->m54->f87(0);
                    M* m = f->modules->m54;
                    m->f75(3, f->modules->m4->f33(0x12e), ev->v8, 5, 0);
                }
                return;
            }
            case 0x83c:
                if (f->modules->m10->f34(0) != 0) {
                    f->modules->m70->change(0x75, f);
                } else {
                    f->modules->m70->change(0x7b, f);
                }
                return;
            case 0x83e:
                f->modules->m70->change(0x83, f);
                return;
            }
            break;
        }
    } else {
        switch (kind) {
        case 0x3c:
            if (obj->a4() == 2) {
                switch (obj->a8()) {
                case 3:
                    self->fighter->modules->m64->onFlag(0x1200003d);
                    break;
                case 0x6e:
                    self->fighter->modules->m4->f72(2, 1);
                    break;
                }
            }
            break;
        case 8: {
            int k = f->modules->m70->getKind();
            if (ev->vC == 0xed && k == 0x116) {
                f->modules->m70->change(0x11a, f);
                ev->b4 = 1;
                ev->b1C = 0;
                return;
            }
            break;
        }
        }
    }
    fn_27_1324D4(self, ev, f, obj, val);
}
