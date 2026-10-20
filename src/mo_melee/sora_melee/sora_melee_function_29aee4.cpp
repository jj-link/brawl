#pragma force_active on
struct Vec3f { float x, y, z; };
#define V(n) virtual void d##n();
struct Acc;
struct A70 { V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15) virtual int getKind(); };
struct M70 { V(0)V(1)V(2) virtual void set(int, Acc*); };
struct M14 { V(0)V(1)V(2) virtual int check(); };
struct Pad8 { int a, b; };
struct M10 : Pad8 { V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)V(30)V(31)V(32)V(33)V(34)V(35)V(36)V(37)V(38)V(39)V(40)V(41)V(42)V(43)V(44)V(45)V(46)V(47)V(48)V(49)V(50)V(51)V(52)V(53)V(54) virtual int isFlag(int, int); };
struct M4 : Pad8 { V(0)V(1)V(2)V(3)V(4)V(5)V(6)V(7)V(8)V(9)V(10)V(11)V(12)V(13)V(14)V(15)V(16)V(17)V(18)V(19)V(20)V(21)V(22)V(23)V(24)V(25)V(26)V(27)V(28)V(29)V(30)V(31)V(32)V(33)V(34)V(35) virtual Vec3f getPos(int, int); };
struct Mods { char p0[4]; M4* m4; char p8[8]; M10* m10; M14* m14; char p18[0x70-0x18]; M70* m70; };
struct Acc { char p[0xd8]; Mods* mods; };
struct Owner1A4 { char p[0x70]; A70* a70; };
struct Obj { char p[0x60]; Acc* acc; char p2[0x1a4-0x64]; Owner1A4* o; };
struct Ev { int kind; int pad; Vec3f pos; };

extern "C" void fn_27_29AEE4(void* self, Obj* obj, Ev* ev) {
    int k = ev->kind;
    if (k == 0x33 || k <= 0x16 || k >= 0x1a) return;
    switch (k) {
    case 0x17: {
        if (obj->o->a70->getKind() != 6 &&
            !(obj->o->a70->getKind() == 8 && obj->o->a70->getKind() == 11)) {
            int s = 8;
            if (!obj->acc->mods->m14->check()) {
                if (obj->acc->mods->m10->isFlag(8, 0)) s = 11;
            }
            Acc* a = obj->acc;
            a->mods->m70->set(s, a);
        }
        ev->pos = obj->acc->mods->m4->getPos(4, 0);
        break;
    }
    }
}
