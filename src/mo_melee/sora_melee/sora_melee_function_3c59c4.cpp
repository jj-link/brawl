#pragma force_active on
#pragma fp_contract off
#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>

class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void* slot6(int);
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual Vec2f slot13(short*);
};
class Class_5860 {
public:
 virtual void fn_27_565F0();
 virtual void fn_27_56888();
 virtual void fn_27_5680C();
 virtual void fn_27_567F8();
 virtual void fn_27_568AC();
 virtual void fn_27_568B4();
 virtual void fn_27_569A4();
 virtual void fn_27_56A4C();
 virtual void fn_27_56AC8();
 virtual void fn_27_56BAC();
 virtual void fn_27_57528();
 virtual void fn_27_576A4();
 virtual float fn_27_57590(unsigned int);
 virtual void fn_27_56BEC(unsigned int, float, float);
};
struct PostureBase { char pad[8]; };
class Posture : public PostureBase { public:
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
 virtual void v8();
 virtual void v9();
 virtual void v10();
 virtual void v11();
 virtual void v12();
 virtual void v13();
 virtual void v14();
 virtual void v15();
 virtual void v16();
 virtual void v17();
 virtual void v18();
 virtual void v19();
 virtual void v20();
 virtual void v21();
 virtual void v22();
 virtual void v23();
 virtual void v24();
 virtual void v25();
 virtual void v26();
 virtual void v27();
 virtual void v28();
 virtual void v29();
 virtual void v30();
 virtual void v31();
 virtual void v32();
 virtual void v33();
 virtual void v34();
 virtual void v35();
 virtual void v36();
 virtual void v37();
 virtual void v38();
 virtual void v39();
 virtual void v40();
 virtual void v41();
 virtual void v42();
 virtual void v43();
 virtual void v44();
 virtual void v45();
 virtual void v46();
 virtual void v47();
 virtual void v48();
 virtual void v49();
 virtual void v50();
 virtual void v51();
 virtual void v52();
 virtual void v53();
 virtual void v54();
 virtual void v55();
 virtual void v56();
 virtual Vec2f stick(int, int);
 virtual void v58();
 virtual void v59();
 virtual void v60();
 virtual void v61();
 virtual void v62();
 virtual void v63();
 virtual void v64();
 virtual void v65();
 virtual void v66();
 virtual void v67();
 virtual void v68();
 virtual void v69();
 virtual void v70();
 virtual void v71();
 virtual void v72();
 virtual void v73();
 virtual void v74();
 virtual void v75();
 virtual void v76();
 virtual void v77();
 virtual void v78();
 virtual void v79();
 virtual void v80();
 virtual void v81();
 virtual void v82();
 virtual void v83();
 virtual void v84();
 virtual void v85();
 virtual void v86();
 virtual void v87();
 virtual void v88();
 virtual void v89();
 virtual float facing(int);
};
struct Modules { char pad0[0x10]; Posture* posture; char pad14[0x50]; Class_5860* work; char pad68[0x14]; soNullable* kinetic; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Energy { char pad[8]; Vec2f speed; };
union Pair { unsigned long long raw; struct { float x, y; } v; };
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
float fn_27_192278(void*, unsigned long);
extern char lbl_27_data_2E5F8[], lbl_27_data_CDF8[];
extern const float lbl_27_rodata_8084;
void fn_27_3C59C4(void*, Access* self) {
 float scale;
 Energy* energy = (Energy*)__dynamic_cast(self->modules->kinetic->slot6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
 short flag = 1;
 Vec2f speed;
 Vec2f::copy(speed, self->modules->kinetic->slot13(&flag));
 float x = speed.m_x;
 Posture* posture = self->modules->posture;
 float mult = fn_27_192278(self, 0xfc0);
 float face = posture->facing(0);
 scale = face * mult;
 float lr = self->modules->work->fn_27_57590(0x21000008);
 posture = self->modules->posture;
 Vec2f stick;
 Vec2f::copy(stick, posture->stick(8, 0));
 float ab = nw4r::math::FAbs(stick.m_x);
 float delta = lr * ab * fn_27_192278(self, 0xfc1);
 if (stick.m_x > lbl_27_rodata_8084)
  x += scale * (lr + delta);
 else
  x += scale * (lr - delta);
 energy->speed = Vec2f(x, lbl_27_rodata_8084);
 self->modules->work->fn_27_56BEC(0x21000010, x, lbl_27_rodata_8084);
}
}