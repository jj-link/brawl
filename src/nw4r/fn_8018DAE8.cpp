#pragma force_active on

struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};

struct Handle {
    char* ptr;
};

extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465AA0[0x20];

extern "C" int fn_8018DAE8(const Handle* arg0, int arg1) {
    char* base = arg0->ptr;
    Resource value(lbl_80465AA0);
    Resource data(base + 0x18);
    int r = fn_8018CFAC(&data, &value, base);

    if (r != 0) {
        if (((unsigned int)(-r | r) >> 31) != 0) {
            char* p = (char*)r + (arg1 + 1) * 16;
            int* q = *(int**)(p + 0x14);
            if (q != 0) {
                return r + (int)q;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
