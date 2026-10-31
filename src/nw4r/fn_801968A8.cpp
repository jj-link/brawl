#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

struct Data {
    unsigned char pad[0x10];
    int offset;
};

struct Handle {
    Data* data;
};

extern char lbl_80465C20[];
extern "C" int fn_8018CFAC(void**, void**);

extern "C" int fn_801968A8(const Handle* arg0)
{
    Data* base = arg0->data;
    int offset = base->offset;
    void* value;
    if (offset != 0) {
        value = (char*)base + offset;
    } else {
        value = 0;
    }
    void* key;
    void** pkey = &key;
    void** const pvalue = &value;

#pragma scheduling on
    return fn_8018CFAC(&(value = value), (key = lbl_80465C20, &key)) != 0;
}
