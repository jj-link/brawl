#pragma force_active on
extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned int id, unsigned int arg);

class FtSonicSlotView {
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
    virtual void slot25(unsigned int a, bool b, bool c);
};

extern "C" void fn_123_9B28(void* object, unsigned int param) {
    if (param == 1) {
        void* acc = *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x60);
        void* mod = *reinterpret_cast<void**>(static_cast<unsigned char*>(acc) + 0xd8);
        FtSonicSlotView* view = *reinterpret_cast<FtSonicSlotView**>(static_cast<unsigned char*>(mod) + 0x88);
        view->slot25(getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(acc, 0x10000036, 0) + 0x30000a, true, true);
    }
}
