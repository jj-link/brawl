#pragma force_active on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_loop_invariants off

struct Data {
    char pad[0x10];
    int offset;
};

struct Handle {
    Data* ptr;
};

extern "C" char* fn_8018CFAC(void**, void**);
extern "C" void fn_80195ED0(void**);
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

extern "C" void fn_8019733C(Handle* self)
{
    unsigned count = getCount(self);
    for (unsigned index = 0; index < count; ++index) {
        void* item = getItem(self, index);
        fn_80195ED0(&item);
    }
}
