#include <so/anim/so_anim_chr.h>
#pragma force_active on

struct Item1 { soAnimChr anim; int id; };
struct Item2 { char pad[0x28]; int id; };
class List1 {
public:
    virtual void v0();
    virtual Item1* get(int);
    virtual void v2();
    virtual int count();
};
class List2 {
public:
    virtual void v0();
    virtual Item2* get(int);
    virtual void v2();
    virtual int count();
};
class Object_vptr_0 {
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
    virtual void slot24(float);
};
extern "C" void fn_27_20498(Item2*);
extern "C" void fn_27_192F0(Object_vptr_0* self) {
    char* p = (char*)self;
    ((soAnimChr*)(p + 0x3c))->rewind();
    if (*(int*)(p + 0x88) != -1) {
        ((soAnimChr*)(p + 0x6c))->rewind();
        *(float*)(p + 0x64) = *(float*)(p + 0x5c);
        self->slot24(*(float*)(p + 0x60));
    }
    int n = (*(List1**)(p + 0x8c))->count();
    for (int i = 0; i < n; i++) {
        if ((*(List1**)(p + 0x8c))->get(i)->id != -1)
            (*(List1**)(p + 0x8c))->get(i)->anim.rewind();
    }
    n = (*(List2**)(p + 0x90))->count();
    for (int i = 0; i < n; i++) {
        if ((*(List2**)(p + 0x90))->get(i)->id != -1)
            fn_27_20498((*(List2**)(p + 0x90))->get(i));
    }
}