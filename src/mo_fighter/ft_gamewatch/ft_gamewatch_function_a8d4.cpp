#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
int fn_27_111E30(void* owner);
unsigned char fn_27_1119B8(void* owner);
void fn_27_1FA94(void* self, int* a, int* b, int c, int d);
void fn_27_1FE18(void* self, void* target);
void fn_27_20084(void* self, float value);
extern const float lbl_107_rodata_C;
}

#define DUMMY(n) virtual void d##n() = 0;
#define DUMMY10(p) DUMMY(p##0) DUMMY(p##1) DUMMY(p##2) DUMMY(p##3) DUMMY(p##4) DUMMY(p##5) DUMMY(p##6) DUMMY(p##7) DUMMY(p##8) DUMMY(p##9)

struct Prefix8 {
    unsigned int fields[2];
};

class Inner0 {
public:
    DUMMY10(0)
    virtual int g12() = 0;
};

class Obj0 : public Prefix8 {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3)
    virtual Inner0* f6() = 0;
    DUMMY(5) DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9) DUMMY(10)
    virtual int f13(int a, unsigned int b, unsigned int c) = 0;
};

struct Inner2 {
    char pad0[0xE8];
    int unkE8;
};

class Obj4 : public Prefix8 {
public:
    DUMMY10(0) DUMMY(10) DUMMY(11) DUMMY(12)
    virtual Inner2* f15() = 0;
    DUMMY(14) DUMMY(15) DUMMY(16) DUMMY(17) DUMMY(18) DUMMY(19)
    DUMMY10(2) DUMMY10(3) DUMMY10(4)
    DUMMY(50) DUMMY(51) DUMMY(52) DUMMY(53) DUMMY(54) DUMMY(55)
    virtual void f58() = 0;
};

class Obj_C0 {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4)
    virtual int f7() = 0;
};

class Obj8 {
public:
    DUMMY10(0) DUMMY10(1) DUMMY10(2) DUMMY10(3) DUMMY10(4) DUMMY10(5) DUMMY10(6) DUMMY10(7) DUMMY10(8) DUMMY10(9)
    DUMMY(100) DUMMY(101)
    virtual void f104(int v) = 0;
};

class WorkModule {
public:
    DUMMY(0) DUMMY(1) DUMMY(2) DUMMY(3) DUMMY(4)
    virtual void setInt(int value, unsigned int index) = 0;
    DUMMY(6) DUMMY(7) DUMMY(8) DUMMY(9) DUMMY(10) DUMMY(11) DUMMY(12)
    virtual void setFloat(float value, unsigned int index) = 0;
};

struct Modules {
    Obj0* o0;
    Obj4* o4;
    Obj8* o8;
    char pad0C[0x64 - 0x0C];
    WorkModule* work;
    char pad68[0xC0 - 0x68];
    Obj_C0* oC0;
};

struct Accesser {
    char pad0[0xD8];
    Modules* modules;
};

struct FighterPrefix {
    char pad[0x3c];
};

class Fighter : public FighterPrefix {
public:
    DUMMY10(0) DUMMY10(1) DUMMY10(2) DUMMY10(3) DUMMY10(4) DUMMY10(5) DUMMY10(6) DUMMY10(7) DUMMY10(8) DUMMY10(9)
    DUMMY10(10) DUMMY10(11) DUMMY10(12) DUMMY10(13) DUMMY10(14) DUMMY10(15) DUMMY10(16) DUMMY10(17)
    DUMMY(180) DUMMY(181) DUMMY(182) DUMMY(183) DUMMY(184)
    virtual void* getOwner() = 0;
    char pad40[0x60 - 0x40];
    Accesser* accesser;
};

extern "C" void fn_107_A8D4(Fighter* self, int param) {
    Obj4* o4 = self->accesser->modules->o4;
    Accesser* accesser = self->accesser;
    soValueAccesser::getConstantFloat(reinterpret_cast<soModuleAccesser*>(accesser), 0xFB7, 0);
    o4->f58();
    if (fn_27_111E30(self->getOwner()) == 0) {
        unsigned char k = fn_27_1119B8(self->getOwner());
        if (k != 0xD && k != 0xC) {
            int arr[4];
            Obj0* o0 = accesser->modules->o0;
            arr[3] = o0->f13(o0->f6()->g12(), 4, 0);
            Obj_C0* c0 = accesser->modules->oC0;
            int e8 = accesser->modules->o4->f15()->unkE8;
            arr[0] = e8;
            arr[1] = e8;
            arr[2] = arr[3];
            int c = c0->f7();
            fn_27_1FA94(reinterpret_cast<char*>(self) + 0x1FDBC, &arr[2], &arr[1], c, 0);
            fn_27_1FE18(reinterpret_cast<char*>((int)self + 0x1FDBC), accesser->modules->o4->f15());
            fn_27_20084(reinterpret_cast<char*>((unsigned int)self + 0x1FDBC), (float)k);
        }
    }
    accesser->modules->o8->f104(1);
    WorkModule* work = accesser->modules->work;
    work->setFloat(lbl_107_rodata_C, 0x11000013);
    work->setFloat(lbl_107_rodata_C, 0x21000006);
    work->setInt(0, 0x10000046);
}
