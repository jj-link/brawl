#pragma force_active on
class Array {
public:
    virtual ~Array();
    virtual unsigned int& at(int index);
};

extern "C" void fn_27_F7658(Array* array, const unsigned int* value, int index) {
    unsigned int& destination = array->at(index);
    destination = *value;
}
