#pragma force_active on
class ArrayInterface {
public:
    virtual void f0() const = 0;
    virtual void f1() = 0;
    virtual void f2() const = 0;
    virtual int f3() const = 0;
    virtual int f4() const = 0;
};

extern "C" bool fn_50_860C(const ArrayInterface* array) {
    return !array->f3();
}
