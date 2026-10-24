#pragma force_active on

struct Resource {
    void* ptr;
    Resource() {}
    Resource(void* p) : ptr(p) {}
};

struct Handle {
    char* ptr;
};

extern "C" char* fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465A80[0x20];

extern "C" char* fn_8018D8E0(const Handle* arg0, int idx) {
    char* base = arg0->ptr;
    Resource value(lbl_80465A80);
    Resource data;
    data.ptr = base + 0x18;

    char* r = (char*)fn_8018CFAC(&data, &value, base);
    if (r != 0) {
        if (((unsigned int)(-(int)r | (int)r) >> 31) != 0) {
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
