#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

struct Data { char pad[0x10]; int offset; };
struct Handle { Data* ptr; };
extern char lbl_80465C00[];
extern "C" char* fn_8018CFAC(char**, char**);

extern "C" char* fn_801969E8(const Handle* self, char** name) {
    Data* base = self->ptr;
    char* data_val;
    if (base->offset != 0) {
        data_val = (char*)base + base->offset;
    } else {
        data_val = 0;
    }
    char* key_val;
    char* r = fn_8018CFAC(&(data_val = data_val), (key_val = (char*)lbl_80465C00, &key_val));
    if (r) {
        char* r_val;
        char* name_val;
        return fn_8018CFAC(&(r_val = r), (name_val = *name, &name_val));
    }
    return 0;
}