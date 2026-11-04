#pragma force_active on
typedef unsigned int u32;

struct Accesser;
struct Kind {
    short value;
    short reserved;
    Kind(short v) : value(v) {}
};
class Queue {
public:
    virtual void slot0();
    virtual int* at(int);
    virtual void slot2();
    virtual void slot3();
    virtual unsigned int empty();
    virtual void slot5();
    virtual void pop();
};
class soControllerModuleImpl {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2(Accesser*, const Kind*, float);
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(const Kind*, void*, Accesser*, int, int);
    virtual int slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void fn_27_151088();
    virtual void fn_27_150688();
    virtual void fn_27_151078();
    virtual void fn_27_151068();
    virtual void fn_27_151010();
    virtual void fn_27_150FFC();
    virtual void fn_27_150FE8();
    virtual void fn_27_150FD4();
    virtual void getStickAngle();
    virtual void getStickDir();
    virtual void isStickSide();
    virtual void fn_27_150FC0();
    virtual void fn_27_150FAC();
    virtual void fn_27_150F98();
    virtual void fn_27_150F84();
    virtual void fn_27_150F70();
    virtual void fn_27_150F5C();
    virtual void fn_27_150F48();
    virtual void fn_27_150F34();
    virtual void fn_27_150F20();
    virtual void fn_27_150EC8();
    virtual void fn_27_150EB4();
    virtual void fn_27_150EA0();
    virtual void fn_27_150E8C();
    virtual void getSubStickDir();
    virtual void isSubStickSide();
    virtual void fn_27_150E78();
};
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
    virtual void processCamera();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void renderOpa();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void init();
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
    virtual void fn_27_248088();
    virtual void slot40();
    virtual void slot41();
    virtual int slot42(int);
};
struct Counter {
    char pad[0xc];
    int count;
};
struct Modules {
    char pad[0x44];
    soControllerModuleImpl* stop;
    char pad48[0x64-0x48];
    Counter* counter;
    void* pad68;
    soControllerModuleImpl* command;
};
struct Accesser {
    char pad[8];
    gfTask* task;
    char padc[0xd8-0xc];
    Modules* modules;
};
class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_73C90();
    virtual void fn_27_73D24();
    virtual void fn_27_74B94();
    virtual void fn_27_75684();
    virtual void fn_27_758E4();
    virtual void fn_27_73DA4();
    virtual void fn_27_73E50();
    virtual void fn_27_73EFC();
    virtual void fn_27_73FA8();
    virtual void fn_27_74054();
    virtual void fn_27_74100();
    virtual void fn_27_741AC();
    virtual void fn_27_74274();
    virtual void fn_27_74334();
    virtual void fn_27_7440C();
    virtual void fn_27_75498();
    virtual void fn_27_75E04();
    virtual void fn_27_75A48();
    virtual void fn_27_75DF8();
    virtual void fn_27_75DF0();
    virtual void fn_27_746B0();
    virtual void fn_27_75DDC();
    virtual void fn_27_75DC8();
    virtual void fn_27_75DB4();
    virtual void fn_27_75DA0();
    virtual void fn_27_75D8C();
    virtual void fn_27_75D78();
    virtual void fn_27_74B08();
    virtual void fn_27_749F8();
    virtual void fn_27_74A04();
    virtual void fn_27_74A7C();
    virtual void fn_27_758F0();
    virtual void fn_27_75C9C();
    virtual void fn_27_74E9C();
    virtual void fn_27_75B18();
    virtual void fn_27_75B2C();
    virtual void fn_27_75B6C();
    virtual void fn_27_74FB0(int, Accesser*);
    char pad4[0x38-4];
    int current;
    char pad3c[8];
    void** entries;
    int size;
    Queue queue;
    char pad50[0x7c-0x50];
    unsigned char flag;
    bool process(Accesser* a) {
        if (queue.empty() == 1U)
            return false;
        while (queue.empty() == 0) {
            int id = *queue.at(0);
            queue.pop();
            if (a->task->slot42(id) != 0) {
                ++a->modules->counter->count;
                current = id;
                if (entries && id > -1 && id < size && entries[id]) {
                    Kind kind(1);
                    a->modules->command->slot8(&kind, entries[id], a, 1, 0);
                }
                fn_27_74FB0(current, a);
                Counter* c = a->modules->counter;
                if (c->count > 0) --c->count;
            }
        }
        return true;
    }
};
extern float lbl_27_rodata_A0C;
extern float lbl_27_rodata_A10;
extern "C" void fn_27_75684(soNullable* self, Accesser* a, u32 mode) {
    if (mode == 1U) {
        Kind kind(1);
        a->modules->command->slot2(a, &kind, lbl_27_rodata_A0C);
        return;
    }
    if (!self->process(a) && !self->flag) {
        if (a->modules->stop->slot9() == 0) {
            Kind kind(0x1d);
            a->modules->command->slot2(a, &kind, lbl_27_rodata_A10);
        } else {
            Kind kind(0x10);
            a->modules->command->slot2(a, &kind, lbl_27_rodata_A10);
        }
    }
}
