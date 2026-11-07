#pragma force_active on
struct Arg;
struct TaskBase { char pad[0x3c]; };
class Task : public TaskBase {
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
virtual void slot40();
virtual void slot41();
virtual int slot42();
};
class Receiver {
public:
virtual void slot0();
virtual void slot1();
virtual void slot2();
virtual void slot3();
virtual void slot4();
virtual void slot5();
virtual void slot6();
virtual void slot7();
virtual void slot8(short*, void*, Arg*, int, int);
};
struct Counter { char pad[12]; int value; };
struct Modules { char pad[0x64]; Counter* counter; char pad68[4]; Receiver* receiver; };
struct Arg { char pad[8]; Task* task; char padc[0xcc]; Modules* modules; };
class soNullable {
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
virtual void fn_27_74FB0(int, Arg*);
char pad[0x34];
int index;
char pad3c[8];
void** entries;
int count;
};
extern "C" void fn_27_74E9C(soNullable* self, int index, Arg* arg) {
    if (arg->task->slot42()) {
        arg->modules->counter->value++;
        self->index = index;
        if (self->entries && index > -1 && index < self->count && self->entries[index]) {
            short value = 1;
            arg->modules->receiver->slot8(&value, self->entries[index], arg, 1, 0);
        }
        self->fn_27_74FB0(self->index, arg);
        if (arg->modules->counter->value > 0) {
            arg->modules->counter->value--;
        }
    }
}