#pragma force_active on
class soArrayVectorCalcInterface {
public:
    virtual void unused0() = 0;
    virtual void unused1() = 0;
    virtual void decrementSize() = 0;
    virtual void setHead(long) = 0;
    virtual void setTail(long) = 0;
};

extern "C" void fn_27_C2C18(
    soArrayVectorCalcInterface&, long, long, long);

extern "C" void erase__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelllll(
    soArrayVectorCalcInterface& array,
    long index, long size, long capacity, long head, long tail)
{
    if (size <= 0 || index < 0 || index >= capacity)
        return;

    if (index == 0) {
        long next = head + 1;
        if (next >= capacity)
            next -= capacity;
        array.setHead(next);
    } else if (index == size - 1) {
        long previous = tail - 1;
        if (previous < 0)
            previous = capacity - 1;
        array.setTail(previous);
    } else {
        fn_27_C2C18(array, head, index, capacity);
        long next = head + 1;
        if (next >= capacity)
            next = 0;
        array.setHead(next);
    }

    array.decrementSize();
}
