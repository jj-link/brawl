#pragma force_active on
class soArrayVectorCalcInterface {
public:
    virtual void v00();
    virtual void v0c();
    virtual void v10();
    virtual void v14(long);
};

class soArrayVectorCalculator {
public:
    static int unshift(soArrayVectorCalcInterface& calc, bool b, long r5, long r6, long r7);
};

int soArrayVectorCalculator::unshift(soArrayVectorCalcInterface& calc, bool b, long r5, long r6, long r7) {
    if (b == 1) {
        return 0;
    }
    long idx = r6 - 1;
    if (idx < 0) {
        idx = r5 - 1;
    }
    calc.v14(idx);
    if (idx == r7) {
        calc.v0c();
    }
    return idx;
}
