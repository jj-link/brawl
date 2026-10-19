#pragma force_active on
class Array {
public:
    virtual void unused();
    virtual int& at(int index);
};

extern "C" void fn_27_11B164(Array* array, const int* value, int index) {
    int& destination = array->at(index);
    destination = *value;
}
