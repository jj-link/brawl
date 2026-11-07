#pragma force_active on
class soNullable {
public:
 virtual void isNull();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5(int, int);
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13(int);
};
struct Modules { char pad[0x64]; soNullable* work; };
struct Object { char pad[0xd8]; Modules* modules; };
extern "C" float fn_27_192278(void*, unsigned long);
extern "C" void fn_27_368D00(void*, Object* obj) {
 obj->modules->work->slot5(-1, 0x10000040);
 fn_27_192278(obj, 0xfa6);
 obj->modules->work->slot13(0x11000017);
 fn_27_192278(obj, 0xfa8);
 obj->modules->work->slot13(0x11000016);
}