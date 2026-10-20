#pragma force_active on

typedef unsigned int u32;

extern "C" {
void* fn_96_14454();
void fn_27_50330(void* manager, int selection);
void fn_27_50190(void* manager, int selection);
}

// Work-manage-like module: getInt at vtable+0x18, setInt at vtable+0x1c.
class WorkModule {
public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual int getInt(u32 index);
    virtual void setInt(int value, u32 index);
};

// Module with a single-int method at vtable slot 61 (offset 0xf4).
class IndirectModule {
public:
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void pad56();
    virtual void pad57();
    virtual void pad58();
    virtual void method(int value);
};

struct Accesser {
    char _0[0xD8];
    void* m_enumeration;
};

extern "C" void fn_96_15108(Accesser* accesser, int param) {
    if (param != 0x12C) {
        WorkModule* work = *(WorkModule**)((char*)accesser->m_enumeration + 0x64);
        int handle = work->getInt(0x20000005);
        if (handle != -1) {
            IndirectModule* module = *(IndirectModule**)((char*)accesser->m_enumeration + 0x1C);
            module->method(0);
            fn_27_50330(fn_96_14454(), handle);
            fn_27_50190(fn_96_14454(), handle);
        }
        work->setInt(-1, 0x20000005);
    }
}
