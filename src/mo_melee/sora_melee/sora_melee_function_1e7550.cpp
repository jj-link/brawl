#pragma force_active on
struct Value {
    int value;
};

struct Array {
    virtual void unused();
    virtual Value& at(int index);
};

extern "C" void fn_27_1E7550(Array* array, const Value& value, int index) {
    array->at(index) = value;
}
