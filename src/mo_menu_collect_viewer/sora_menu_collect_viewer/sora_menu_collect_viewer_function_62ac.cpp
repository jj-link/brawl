#include <types.h>
#pragma force_active on

extern char lbl_6_data_0[];
extern "C" void printf__5MuMsgFUlPCce(void*, unsigned long, const char*, ...);

class Viewer {
public:
    char pad[0x3c];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual void unused16();
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void unused39();
    virtual void unused40();
    virtual void unused41();
    virtual void unused42();
    virtual void update(void*);
};

extern "C" void fn_6_62AC(void* self) {
    char* s = (char*)self;

    printf__5MuMsgFUlPCce(
        *(void**)(*(char**)(s + 0x1ac) + 0x1c7c), 0xc, lbl_6_data_0);
    printf__5MuMsgFUlPCce(
        *(void**)(*(char**)(s + 0x1ac) + 0x1c7c), 0xd, lbl_6_data_0);
    printf__5MuMsgFUlPCce(
        *(void**)(*(char**)(s + 0x1ac) + 0x1c7c), 0xe, lbl_6_data_0);

    ((Viewer*)self)->update(
        *(void**)(*(char**)(s + 0x1ac) + 0x190));
}
