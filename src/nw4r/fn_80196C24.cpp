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
extern "C" char* fn_8018CFAC(void**, void**);
extern char lbl_80465C20[0x20];

extern "C" char* fn_80196C24(const Handle* self, int index)
{
    Data* base = self->ptr;
    int offset = base->offset;
    void* key;
    void* value;
    if (offset != 0) {
        value = (char*)base + offset;
    } else {
        value = 0;
    }
#pragma scheduling on
    char* r = fn_8018CFAC(&(value = value), (key = lbl_80465C20, &key));
    if (r != 0) {
        if (((unsigned)(-(int)r | (int)r) >> 31) != 0) {
            int off = *(int*)((char*)r + ((index + 1) << 4) + 0x14);
            if (off != 0)
                return r + off;
            return 0;
        }
        return 0;
    }
    return 0;
}
