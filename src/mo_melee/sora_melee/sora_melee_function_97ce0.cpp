#include <types.h>
#pragma force_active on

class soNullable {
public:
    virtual void isNull();                 // 0x08
    virtual void fn_27_97968();            // 0x0c
    virtual void fn_27_97C48();            // 0x10
    virtual void fn_27_97CE0();            // 0x14
    virtual void fn_27_97F80();            // 0x18
    virtual void fn_27_98194();            // 0x1c
    virtual void fn_27_986B0();            // 0x20
    virtual void fn_27_9881C();            // 0x24
    virtual void fn_27_988B8();            // 0x28
    virtual void fn_27_98924();            // 0x2c
    virtual void fn_27_991C4();            // 0x30
    virtual void fn_27_993AC();            // 0x34
    virtual void fn_27_997C4();            // 0x38
    virtual void fn_27_99B2C();            // 0x3c
    virtual void fn_27_99B64();            // 0x40
    virtual void fn_27_999BC();            // 0x44
    virtual void fn_27_99A70();            // 0x48
    virtual void fn_27_99C14();            // 0x4c
    virtual void fn_27_99CD0();            // 0x50
    virtual void fn_27_99D88();            // 0x54
    virtual void fn_27_99E80();            // 0x58
    virtual void fn_27_99E8C();            // 0x5c
    virtual void fn_27_99EA8();            // 0x60
    virtual void fn_27_99EB4();            // 0x64
    virtual void fn_27_99EDC(s32, s32, s32); // 0x68
    virtual void fn_27_99F08();            // 0x6c
    virtual void fn_27_9A0E4();            // 0x70
    virtual void fn_27_9A0F8(s32, s32);    // 0x74
    virtual void fn_27_9A11C();            // 0x78
    virtual void fn_27_9A128();            // 0x7c
    virtual void fn_27_9A134();            // 0x80
    virtual void fn_27_9A140();            // 0x84
    virtual void fn_27_9A14C();            // 0x88
    virtual void fn_27_9A158();            // 0x8c
    virtual void fn_27_97E6C();            // 0x90
    virtual void fn_27_9A1A4();            // 0x94
    virtual void fn_27_9A1EC();            // 0x98
    virtual void fn_27_9A1F4();            // 0x9c
    virtual void fn_27_9A380();            // 0xa0
    virtual void fn_27_9A56C();            // 0xa4
    virtual void fn_27_9A81C();            // 0xa8
};

extern "C" void fn_27_9FF80(void* p);

extern "C" void fn_27_97CE0(soNullable* self) {
    self->fn_27_9A0F8(0, 0);
    self->fn_27_99B64();
    self->fn_27_99CD0();
    self->fn_27_99EDC(4, 1, 1);
    fn_27_9FF80(reinterpret_cast<char*>(self) + 0x124);
    self->fn_27_9A81C();
}
