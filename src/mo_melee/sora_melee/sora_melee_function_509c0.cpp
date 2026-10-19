#pragma force_active on
class Array {
public:
    virtual ~Array();
    virtual int& at(unsigned int index) = 0;
};

extern "C" void fn_27_509C0(Array* array, const int& value, unsigned int index) {
    int& target = array->at(index);
    target = value;
}
