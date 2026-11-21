#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants off

struct Data { char pad[0x10]; int offset; };
struct Handle { Data* ptr; };
extern "C" char* fn_8018CFAC(void**, void**);
extern "C" bool fn_80195D64(Handle*, const Handle*);
extern char lbl_80465BE0[0x20];

inline unsigned getCount(const Handle* self)
{
    Data* base = self->ptr;
    int offset = base->offset;
    void* value;
    void* key;
    if (offset != 0)
        value = (char*)base + offset;
    else
        value = 0;
    char* r = fn_8018CFAC(&(value = value),
                         (key = lbl_80465BE0, &key));
    if (r != 0) {
        if (((unsigned)(-(int)r | (int)r) >> 31) != 0)
            return *(unsigned*)(r + 4);
        return 0;
    }
    return 0;
}

inline void* getItem(const Handle* self, unsigned index)
{
    Data* base = self->ptr;
    int offset = base->offset;
    void* key;
    void* value;
    void* resolved;
    if (offset != 0)
        resolved = (char*)base + offset;
    else
        resolved = 0;
    char* r = fn_8018CFAC(&(value = resolved),
                         (key = lbl_80465BE0, &key));
    if (r != 0) {
        if (((unsigned)(-(int)r | (int)r) >> 31) != 0) {
            int off = *(int*)(r + ((index + 1) << 4) + 0x14);
            if (off != 0)
                return r + off;
            return 0;
        }
        return 0;
    }
    return 0;
}

extern "C" int fn_801971D0(const Handle* self, const Handle* arg1)
{
    void* item;
    Handle other;
    int next;
    int result;
    unsigned count;
    unsigned index;
    count = getCount(self);
    result = 1;
    for (index = 0; index < count; ++index) {
        if (fn_80195D64((Handle*)&(item = getItem(self, index)), (next = 0, other.ptr = arg1->ptr, &other)) && result != 0)
            next = 1;
        result = next;
    }
    return result;
}
