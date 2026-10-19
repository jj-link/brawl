#pragma force_active on
struct NessSubobject {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void invoke();
};

extern "C" void fn_101_19FB4(void* object)
{
    reinterpret_cast<NessSubobject*>(
        static_cast<unsigned char*>(object) + 0x182C)->invoke();
}
