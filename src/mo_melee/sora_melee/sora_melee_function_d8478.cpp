#pragma force_active on
struct Value {
    unsigned int first;
    unsigned int second;
};

class Array {
public:
    virtual ~Array();
    virtual Value& at(int index) = 0;
};

extern "C" void fn_27_D8478(Array* array, const Value& value, int index) {
    array->at(index) = value;
}
