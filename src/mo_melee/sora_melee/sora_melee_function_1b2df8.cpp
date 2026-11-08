#pragma force_active on

#include <types.h>
#include <so/so_array_vector_calculator.h>

class wnPikminPikmin;

template <class T>
class soArrayVectorAbstract {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual s32 slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual s32 slot13();
    virtual bool slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual T& slot26(s32);
    virtual s32 slot27();
    virtual s32 slot28();
    virtual void slot29(s32);

    void insert(s32 index, const T& newElement);

    s32 calc;
};

template <class T>
void soArrayVectorAbstract<T>::insert(s32 index, const T& newElement) {
    s32 pos = soArrayVectorCalculator::insert(
        *reinterpret_cast<soArrayVectorCalcInterface*>(&calc), index, slot14(), slot3(),
        slot13(), slot27(), slot28());
    T& element = slot26(pos);
    element = newElement;
    slot29(slot3() + 1);
}

template void soArrayVectorAbstract<wnPikminPikmin*>::insert(s32, wnPikminPikmin* const&);
