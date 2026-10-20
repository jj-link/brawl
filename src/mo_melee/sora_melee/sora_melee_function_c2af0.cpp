#pragma force_active on
struct soArrayVectorCalcInterface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(long);
};

class soArrayVectorCalculator {
public:
    static void postInitialize(soArrayVectorCalcInterface& iface, long a, long b);
};

void soArrayVectorCalculator::postInitialize(soArrayVectorCalcInterface& iface, long a, long b) {
    if (a >= b) {
        iface.slot4(0);
        iface.slot1();
    } else {
        iface.slot4(a);
    }
}
