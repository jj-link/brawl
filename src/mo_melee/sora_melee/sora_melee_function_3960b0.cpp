#pragma force_active on
struct gfTask_base { char pad[0x3c]; };
class gfTask : public gfTask_base {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12();
virtual void slot13();
virtual void slot14();
virtual void slot15();
virtual void slot16();
virtual void slot17();
virtual void slot18();
virtual void slot19();
virtual void slot20();
virtual void slot21();
virtual void slot22();
virtual void slot23();
virtual void slot24();
virtual void slot25();
virtual void slot26();
virtual void slot27();
virtual void slot28();
virtual void slot29();
virtual void slot30();
virtual void slot31();
virtual void slot32();
virtual void slot33();
virtual void slot34();
virtual void slot35();
virtual void slot36();
virtual void slot37();
virtual void slot38();
virtual void slot39();
virtual int slot40();
};
class soNullable {
public:
virtual void isNull();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5(int, unsigned int);
virtual void slot6();
virtual void slot7();
virtual void slot8();
virtual void slot9();
virtual void slot10();
virtual void slot11();
virtual void slot12(int, int, int);
};
struct Modules { char pad[0x64]; soNullable* work; char pad2[0x28]; soNullable* other; };
struct Owner { char pad[8]; gfTask* task; char pad2[0xcc]; Modules* modules; };
extern "C" void fn_27_3960B0(void*, Owner* owner) {
 int result = owner->task->slot40();
 int kind = 11;
 if (result == 0x20) kind = 9;
 owner->modules->other->slot12(kind, 1, -1);
 owner->modules->work->slot5(kind, 0x20000008);
}