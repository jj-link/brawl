#pragma force_active on

struct Resource {
    char* ptr;
    Resource() {}
    Resource(void* p) : ptr((char*)p) {}

    bool valid() const {
        return (unsigned)(-(int)ptr | (int)ptr) >> 31;
    }
};

extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465AC0[0x20];

struct Handle {
    char* ptr;
};

extern "C" char* GetResAnmTexPat__Q34nw4r3g3d7ResFileFi(const Handle* arg0, int arg1) {
    char* base = arg0->ptr;
    Resource data;
    Resource value(lbl_80465AC0);
    data.ptr = base + 0x18;

    Resource result((void*)fn_8018CFAC(&data, &value, base));
    if (result.ptr != 0) {
        if (result.valid()) {
            int offset = *(int*)(result.ptr + ((arg1 + 1) << 4) + 0x14);
            if (offset != 0) {
                return result.ptr + offset;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
