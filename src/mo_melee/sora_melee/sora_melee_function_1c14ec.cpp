#pragma force_active on
struct Value {
    int value;
};

class Array {
public:
    virtual ~Array();
    virtual Value& at(unsigned int index) = 0;
};

extern "C" void fn_27_1C14EC(Array* array, const Value& value, unsigned int index) {
    array->at(index) = value;
}
