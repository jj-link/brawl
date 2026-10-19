#pragma force_active on
struct Array {
    virtual ~Array();
    virtual void unused_0C();
    virtual void unused_10();
    virtual int size() const;
};

extern "C" bool fn_104_BF74(const Array* array) {
    return array->size() == 0;
}
