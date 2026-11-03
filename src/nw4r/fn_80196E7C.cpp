#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off

struct Hdr { char pad[0x10]; int off; };
struct Handle { Hdr* ptr; };

extern char lbl_80465C60[0x20];
extern "C" char* fn_8018CFAC(void**, void**);

extern "C" char* fn_80196E7C(const Handle* self, int index) {
    void* value;
    void* key;
    Hdr* base = self->ptr;
    if (base->off != 0) {
        value = (char*)base + base->off;
    } else {
        value = 0;
    }
#pragma scheduling on
    char* r = fn_8018CFAC(&(value = value), (key = lbl_80465C60, &key));
    if (r) {
        unsigned v = (unsigned)r;
        if (((-v | v) >> 31) != 0) {
            int off = *(int*)(r + (index + 1) * 16 + 0x14);
            if (off) return r + off;
            return 0;
        }
        return 0;
    }
    return 0;
}