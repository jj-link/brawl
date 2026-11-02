#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off
struct Data {
    char pad[0x10];
    int offset;
};
struct Handle {
    Data* ptr;
};
extern "C" int fn_8018CFAC(void**, void**);
extern char lbl_80465C00[0x20];

extern "C" int fn_80196B1C(const Handle* self)
{
    Data* base = self->ptr;
    int offset = base->offset;
    void* value;
    void* key;
    if (offset != 0) {
        value = (char*)base + offset;
    } else {
        value = 0;
    }
#pragma scheduling on
    int r = fn_8018CFAC(&(value = value), (key = lbl_80465C00, &key));
    if (r != 0) {
        if (((unsigned int)(-r | r) >> 31) != 0)
            return *(int*)((char*)r + 4);
        return 0;
    }
    return 0;
}
