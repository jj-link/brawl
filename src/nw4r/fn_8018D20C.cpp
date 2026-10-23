#pragma force_active on

struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};

struct Handle {
    char* ptr;
};

extern "C" char* fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465A00[];

extern "C" char* fn_8018D20C(const Handle* arg0, int arg1) {
    Resource value(lbl_80465A00);
    Resource data(arg0->ptr + 0x18);
    char* r = fn_8018CFAC(&data, &value, arg0->ptr);
    if (r != 0) {
        if (((unsigned int)(-(int)r | (int)r) >> 31) != 0) {
            int off = *(int*)(r + (arg1 + 1) * 0x10 + 0x14);
            if (off != 0) {
                return r + off;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
