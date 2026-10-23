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
extern char lbl_80465B00[];

extern "C" void* fn_8018E068(const Handle* arg0, int arg1) {
    char* base = arg0->ptr;
    Resource data;
    Resource value(lbl_80465B00);
    data.ptr = base + 0x18;

    char* result = fn_8018CFAC(&data, &value, base);
    if (result != 0) {
        if (((unsigned)(-(int)result | (int)result)) >> 31) {
            int offset = *(int*)(result + (arg1 + 1) * 16 + 0x14);
            if (offset != 0) {
                return result + offset;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
