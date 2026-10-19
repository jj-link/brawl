#pragma force_active on
class ArrayLike {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual int isEmpty() const = 0;
};

extern "C" bool fn_70_CB54(const ArrayLike* array) {
    return !array->isEmpty();
}
