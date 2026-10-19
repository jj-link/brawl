#pragma force_active on
struct Array {
    virtual void slot0() const = 0;
    virtual void slot1() const = 0;
    virtual void slot2() const = 0;
    virtual int size() const = 0;
};

extern "C" bool fn_66_EEEC(const Array* array) {
    return array->size() == 0;
}
