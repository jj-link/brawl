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
extern "C" char* fn_8018CFAC(char**, char**);
extern char lbl_80465C00[0x20];

extern "C" char* fn_80196A70(const Handle* arg0, int arg1)
{
    Data* base = arg0->ptr;
    char* key;
    char* value;
    int offset = base->offset;
    if (offset != 0) {
        value = (char*)base + offset;
    } else {
        value = 0;
    }
    char* r = fn_8018CFAC(&(value = value), (key = lbl_80465C00, &key));
    if (r != 0) {
        if (((unsigned int)(-(int)r | (int)r) >> 31) != 0) {
            int off = *(int*)(r + ((arg1 + 1) << 4) + 0x14);
            if (off != 0)
                return r + off;
            return 0;
        }
        return 0;
    }
    return 0;
}