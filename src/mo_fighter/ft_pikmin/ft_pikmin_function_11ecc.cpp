#pragma force_active on
struct PikminDispatchObject
{
    virtual int slot00() = 0;
    virtual int slot01() = 0;
    virtual int slot02() = 0;
    virtual int slot03() = 0;
    virtual int slot04() = 0;
    virtual int slot05() = 0;
    virtual int slot06() = 0;
    virtual int slot07() = 0;
    virtual int slot08() = 0;
    virtual int slot09() = 0;
    virtual int slot10() = 0;
    virtual int slot11() = 0;
    virtual int slot12() = 0;
    virtual int slot13() = 0;
    virtual int slot14() = 0;
    virtual int slot15() = 0;
    virtual int slot16() = 0;
    virtual int slot17() = 0;
    virtual int slot18() = 0;
    virtual int slot19() = 0;
    virtual int slot20() = 0;
    virtual int slot21() = 0;
    virtual int slot22() = 0;
    virtual int slot23() = 0;
    virtual int slot24() = 0;
};

extern "C" int fn_113_11ECC(PikminDispatchObject *object)
{
    return object->slot24();
}
