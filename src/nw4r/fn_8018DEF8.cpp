#pragma force_active on

struct Resource {
    char* ptr;

    Resource() {}
    Resource(void* p) : ptr((char*)p) {}

    bool valid() const {
        return (unsigned)(-(int)ptr | (int)ptr) >> 31;
    }

    char* get(int index) const {
        if (valid()) {
            int offset = *(int*)(ptr + ((index + 1) << 4) + 0x14);
            if (offset != 0)
                return ptr + offset;
            return 0;
        }
        return 0;
    }
};

extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern "C" unsigned char lbl_80465AE0[0x20];

struct Handle {
    char* ptr;
};

extern "C" char* fn_8018DEF8(const Handle* arg0, int arg1) {
    char* base = arg0->ptr;
    Resource value(lbl_80465AE0);
    Resource data;
    data.ptr = base + 0x18;

    Resource result((void*)fn_8018CFAC(&data, &value, arg0->ptr));
    if (result.ptr != 0) {
        return result.get(arg1);
    }
    return 0;
}
