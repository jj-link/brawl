#pragma force_active on
typedef int s32;

class soArrayVectorCalcInterface {
public:
    virtual ~soArrayVectorCalcInterface() { }
    virtual void substitution(s32, s32) = 0;
    virtual void offFull() = 0;
    virtual void setTopIndex(s32) = 0;
    virtual void setLastIndex(s32) = 0;
};

class soArrayVectorCalculator {
public:
    static void shift(soArrayVectorCalcInterface& interface, bool isEmpty, long capacity, long topIndex);
};

void soArrayVectorCalculator::shift(soArrayVectorCalcInterface& interface, bool isEmpty, long capacity, long topIndex) {
    if (isEmpty != true) {
        long next = topIndex + 1;
        if (next >= capacity) {
            next -= capacity;
        }
        interface.setTopIndex(next);
        interface.offFull();
    }
}
