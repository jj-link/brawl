#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

struct Handle { char* ptr; };
extern "C" char* fn_8018CFAC(char**, char**);
extern char lbl_80465C60[0x20];

extern "C" char* fn_80196F28(const Handle* arg0, int arg1) {
    char* base = arg0->ptr;
    char* key_val;
    char* data_val;
    int offset = *(int*)(base + 0x10);
    if (offset != 0) {
        data_val = base + offset;
    } else {
        data_val = 0;
    }
    char* r = fn_8018CFAC(&(data_val = data_val), (key_val = (char*)lbl_80465C60, &key_val));
    if (r != 0) {
        if (((unsigned)(-(int)r | (int)r) >> 31) != 0) {
            int off = *(int*)(r + ((arg1 + 1) << 4) + 0x14);
            if (off != 0)
                return r + off;
            return 0;
        }
        return 0;
    }
    return 0;
}