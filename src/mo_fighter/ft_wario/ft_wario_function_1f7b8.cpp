
#pragma force_active on
class Class_6F70 {
public:
 virtual void fn_110_6E04();
 virtual void fn_110_FFB8();
 virtual void fn_110_12AE8();
 virtual void fn_110_12AE4();
 virtual void fn_110_12AE0();
 virtual void fn_110_12ADC();
 virtual void fn_110_12AD4();
 virtual void fn_110_12B1C();
 virtual void fn_110_12B14();
 virtual void fn_110_12B0C();
 virtual void fn_110_12B04();
 virtual void fn_110_12AFC();
 virtual float fn_110_12A94(int);
 virtual void fn_110_12AC8();
 virtual void fn_110_12ABC();
 virtual void fn_110_12AB4();
 virtual void fn_110_12AA8();
 virtual int fn_110_12AA0(int);
};
class Class_70F0 {
public:
 virtual void fn_110_6E04();
 virtual void fn_110_FF5C();
 virtual void fn_110_12CAC();
 virtual void fn_110_12CA4(int, void*);
 virtual void fn_110_12C9C();
 virtual void fn_110_12C94();
 virtual void fn_110_12C8C();
 virtual void fn_110_12C84();
 virtual void fn_110_12C7C();
 virtual void fn_110_12C74();
 virtual void fn_110_12C6C();
 virtual void fn_110_12C64();
 virtual void fn_110_12C5C();
 virtual void fn_110_12C54();
 virtual void fn_110_12C04();
 virtual void fn_110_12C4C();
 virtual int fn_110_12C3C();
 virtual void fn_110_12C2C();
};
class Class_80F8 {
public:
 virtual void fn_110_15550();
 virtual void fn_110_15548();
 virtual void fn_110_15540();
 virtual void fn_110_15538();
 virtual void fn_110_15530();
 virtual void fn_110_15528();
 virtual void fn_110_15520();
 virtual void fn_110_15518();
 virtual void fn_110_1550C();
 virtual void fn_110_15504();
 virtual void fn_110_154FC();
 virtual void fn_110_154F4();
 virtual void fn_110_154F0();
 virtual void fn_110_154EC();
 virtual void fn_110_154E8();
 virtual void fn_110_154E4();
 virtual void fn_110_154DC();
 virtual void fn_110_154D8();
};
struct Modules { char pad[0x64]; Class_6F70* work; char pad2[8]; Class_70F0* status; };
struct Owner { char pad[0xd8]; Modules* modules; };
struct Fighter { char pad[0x60]; Owner* owner; };
extern "C" {
extern void* lbl_27_bss_F0;
extern const float lbl_110_rodata_1D0;
void fn_27_12E7C8(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
int fn_27_5BEA8(void*);
void fn_110_1F7B8(Fighter* fighter) {
 fn_27_12E7C8(fighter);
 Modules* modules = fighter->owner->modules;
 Class_6F70* work = modules->work;
 Class_70F0* status = modules->status;
 if (!lbl_27_bss_F0) {
  void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
  if (singleton) singleton = fn_27_5BCD0(singleton);
  lbl_27_bss_F0 = singleton;
 }
 if (fn_27_5BEA8(lbl_27_bss_F0) && work->fn_110_12AA0(0x1200003d) && work->fn_110_12A94(0x11000013) < lbl_110_rodata_1D0 && status->fn_110_12C3C() != 0x116)
  status->fn_110_12CA4(0x116, fighter->owner);
}
}
