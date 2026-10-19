#pragma force_active on
struct DededeTargetBase {
    int _0;
    int _4;
};

struct DededeTarget : DededeTargetBase {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void slot3() = 0;
    virtual void slot4() = 0;
    virtual void slot5() = 0;
    virtual void slot6() = 0;
    virtual void slot7() = 0;
    virtual void slot8() = 0;
    virtual void slot9() = 0;
    virtual void slot10() = 0;
    virtual void slot11() = 0;
    virtual void slot12() = 0;
    virtual void slot13() = 0;
    virtual void slot14() = 0;
    virtual void slot15() = 0;
    virtual void slot16() = 0;
    virtual void slot17() = 0;
    virtual void slot18() = 0;
    virtual void slot19() = 0;
    virtual void slot20() = 0;
    virtual void slot21(int) = 0;
};

class soModuleAccesser;

extern "C" void fn_117_F2BC(void*, soModuleAccesser* accesser) {
    void* outer = *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(accesser) + 0xd8);
    DededeTarget* target = *reinterpret_cast<DededeTarget**>(reinterpret_cast<unsigned char*>(outer) + 4);
    target->slot21(5);
}
