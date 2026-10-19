#pragma force_active on
class LucasInterface {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
};

extern "C" void fn_114_19B1C(void* object) {
    reinterpret_cast<LucasInterface*>(
        static_cast<char*>(object) + 0x182c)->slot6();
}
