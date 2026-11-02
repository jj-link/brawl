#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma scheduling on

struct Obj { unsigned char pad[0x10]; int offset; };
struct Handle { Obj* ptr; };
extern char lbl_80465C60[0x20];
extern "C" int fn_8018CFAC(void**, void**);

extern "C" int fn_80196FD4(const Handle* self) {
    Obj* base = self->ptr;
    int offset = base->offset;
    void* value;
    if (offset != 0) value = (char*)base + offset; else value = 0;
    void* key;
    int r = fn_8018CFAC(&(value = value), (key = lbl_80465C60, &key));
    if (r != 0) {
        if (((unsigned)(-(int)r | (int)r) >> 31) != 0) return *(int*)((char*)r + 4);
        return 0;
    }
    return 0;
}
