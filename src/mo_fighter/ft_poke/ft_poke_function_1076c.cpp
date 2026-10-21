#pragma force_active on

typedef unsigned int u32;

struct Module {
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
    virtual void slot19(u32);
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
    virtual void slot34(int, void*);
};

extern "C" void fn_116_1076C(void* fighter, u32 arg) {
    if (arg == 1U) {
        void* accesser = *(void**)((char*)fighter + 0x60);
        void* data = *(void**)((char*)accesser + 0xD8);
        Module* module = *(Module**)((char*)data + 0x70);
        module->slot34(3, accesser);

        accesser = *(void**)((char*)fighter + 0x60);
        data = *(void**)((char*)accesser + 0xD8);
        module = *(Module**)((char*)data + 0x64);
        module->slot19(0x12000000U);
    } else {
        void* accesser = *(void**)((char*)fighter + 0x60);
        void* data = *(void**)((char*)accesser + 0xD8);
        Module* module = *(Module**)((char*)data + 0x70);
        module->slot34(2, accesser);
    }
}
