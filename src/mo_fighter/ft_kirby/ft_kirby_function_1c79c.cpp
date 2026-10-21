#pragma force_active on
extern "C" void* fn_96_A390();
extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);

extern "C" {
extern char lbl_96_data_BC20[];
extern char lbl_96_data_BC68[];
}

class ValueTarget {
public:
    virtual void unused();
    virtual int* get(int);
};

static inline void* selectTarget(void* self, int kind, int variant)
{
    switch (kind) {
    case 0:
        switch (variant) {
        case 0:
            return (char*)self + 0x195F8;
        case 1:
            return (char*)self + 0x19D04;
        case 2:
            return fn_96_A390();
        default:
            return fn_96_A390();
        }
    default:
        return fn_96_A390();
    }
}

extern "C" void fn_96_1C79C(void* self, int kind, int variant,
                           const int* values, int count, int start)
{
    if (values != 0 && count > 0) {
        ValueTarget* target = (ValueTarget*)__dynamic_cast(
            selectTarget(self, kind, variant), 0,
            lbl_96_data_BC20, lbl_96_data_BC68, 0);

        if (target) {
            for (int i = 0; i < count; ++i) {
                int* dest = target->get(i + start);
                *dest = values[i];
            }
        }
    }
}
