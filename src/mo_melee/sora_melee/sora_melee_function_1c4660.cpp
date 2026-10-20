#pragma force_active on
struct Array {
    virtual void unused();
    virtual int* at(int index);
};

extern "C" void fn_27_1C4660(Array* array, const int* value, int index) {
    int* destination = array->at(index);
    *destination = *value;
}
