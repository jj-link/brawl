#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned int);
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
    virtual int slot17(unsigned int);
    virtual void slot18(unsigned int);
    virtual void slot19(unsigned int);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22(int);
};

extern "C" void fn_27_2FB7FC(void*, u8* obj) {
    soNullable* work = *(soNullable**)(*(u8**)(obj + 0xd8) + 0x64);
    if (work->slot17(0x1200003e) != 0) {
        soNullable* w = *(soNullable**)(*(u8**)(obj + 0xd8) + 0x64);
        w->slot22(2);
        w->slot5(0, 0x10000042);
        w->slot18(0x22000010);
        soNullable* status = *(soNullable**)(*(u8**)(obj + 0xd8) + 0x14);
        if (status->slot3() == 0) {
            w->slot19(0x22000014);
        } else {
            w->slot18(0x22000014);
        }
        work->slot19(0x1200003e);
    }
}
