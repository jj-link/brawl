#pragma force_active on

struct Resource {
    void* ptr;
    Resource() {}
    Resource(void* p) : ptr(p) {}
};

struct Handle {
    char* ptr;
};

extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465B00[];

extern "C" char* fn_8018E100(const Handle* self, int idx) {
    char* base = self->ptr;
    Resource value(lbl_80465B00);
    Resource data;
    data.ptr = base + 0x18;

    char* r = (char*)fn_8018CFAC(&data, &value, base);
    if (r != 0) {
        unsigned int t = (unsigned int)(-(int)r | (int)r) >> 31;
        if (t != 0) {
            int off = *(int*)(r + (idx + 1) * 16 + 0x14);
            if (off != 0) {
                return r + off;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
