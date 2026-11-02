#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

struct Data {
    char pad[0x10];
    int offset;
};

struct Handle {
    Data* data;
};

extern "C" char lbl_80465C40[];
extern "C" int fn_8018CFAC(void**, void**);

extern "C" int fn_80196DFC(const Handle* self)
{
    Data* base = self->data;
    int offset = base->offset;
    void* data;
    if (offset != 0) {
        data = (char*)base + offset;
    } else {
        data = 0;
    }
    void* name;
    void** pdata = &data;
    void** pname = &name;

#pragma scheduling on
    int r = fn_8018CFAC(&(data = data), (name = (void*)lbl_80465C40, &name));
    if (r != 0) {
        if (((unsigned int)(-r | r)) >> 31)
            return *(int*)((char*)r + 4);
        return 0;
    }
    return 0;
}
