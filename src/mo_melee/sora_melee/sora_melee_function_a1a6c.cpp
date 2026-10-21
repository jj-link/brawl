#pragma force_active on
struct acCmdInterpreterStackData {
    long kind;
    long intData;
    bool boolData;
    const void* addressData;
    float floatData;
};

template <class T>
class soArrayVectorAbstract {
public:
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
    virtual void slot21() = 0;
    virtual void slot22() = 0;
    virtual void slot23() = 0;
    virtual void slot24() = 0;
    virtual void slot25() = 0;
    virtual T& getArrayValueConst(long) = 0;

    void substitution(long, long);
};

template <>
void soArrayVectorAbstract<acCmdInterpreterStackData>::substitution(
    long subIndex, long targetIndex)
{
    acCmdInterpreterStackData& subElement = getArrayValueConst(subIndex);
    acCmdInterpreterStackData& targetElement = getArrayValueConst(targetIndex);
    targetElement = subElement;
}
