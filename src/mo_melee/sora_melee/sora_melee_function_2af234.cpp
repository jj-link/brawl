#pragma force_active on
class Class_20958 {
public:
    virtual void fn_27_C76A8();
    virtual void fn_27_C7528();
    virtual void fn_27_C7538();
    virtual int size__41soArrayContractibleTable_C12soStatusData_CFv();
    unsigned int flags;
};

extern "C" void fn_27_2AF234(Class_20958* self, int start, const int* value, int count) {
    if (count != 0) {
        if (count + start >= self->size__41soArrayContractibleTable_C12soStatusData_CFv()) {
            count = self->size__41soArrayContractibleTable_C12soStatusData_CFv() - start;
        }
        int index = (int)((self->flags << 9) & 0xFFC00000) >> 23;
        while (count > 0) {
            if (start > 0) {
                --start;
            } else {
                --count;
                *(int*)((char*)self + index * 12 + 0x10) = *value;
            }
            index = *(short*)((char*)self + index * 12 + 0x16);
            if (index < 0) break;
        }
    }
}
