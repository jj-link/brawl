#pragma force_active on

class Class_54750 {
public:
    virtual void fn_27_25EF44();
    virtual void fn_27_21CB30();
    virtual void fn_27_25EBF8();
    virtual int fn_27_21CD40();

    unsigned int flags;
};

extern "C" void fn_27_25EE6C(Class_54750* self, int start, const int* value, int count) {
    if (count != 0) {
        if (count + start >= self->fn_27_21CD40()) {
            count = self->fn_27_21CD40() - start;
        }

        int index = (int)((self->flags << 7) & 0xFF000000) >> 25;
        while (count > 0) {
            if (start > 0) {
                --start;
            } else {
                --count;
                *(int*)((char*)self + index * 12 + 0xc) = *value;
            }

            index = *(signed char*)((char*)self + index * 12 + 0x11);
            if (index < 0) {
                break;
            }
        }
    }
}
