#pragma force_active on
extern "C" double __fabs(double);
extern "C" double atan2(double, double);

inline double fabs(double value) {
    return __fabs(value);
}

class soControllerModuleImpl {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual float getStickX();
    virtual void slot4C();
    virtual float getStickY();

    float getStickDir();
};

float soControllerModuleImpl::getStickDir() {
    float x = fabs(getStickX());
    return atan2(getStickY(), x);
}
