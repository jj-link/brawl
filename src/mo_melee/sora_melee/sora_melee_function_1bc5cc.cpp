#pragma force_active on
class Array {
public:
    virtual void unused();
    virtual int& at(int index);
};

extern "C" void fn_27_1BC5CC(Array* array, const int* value, int index) {
    int& destination = array->at(index);
    destination = *value;
}
