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
extern char lbl_80465A80[0x20];

extern "C" int GetResAnmVisNumEntries__Q34nw4r3g3d7ResFileFv(const Handle* self) {
    char* base = self->ptr;
    Resource data;
    Resource value(lbl_80465A80);
    data.ptr = base + 0x18;
    char* r = (char*)fn_8018CFAC(&data, &value, base);
    if (r != 0) {
        unsigned int t = (unsigned int)(-(int)r | (int)r) >> 31;
        if (t != 0) {
            return *(int*)(r + 4);
        }
        return 0;
    }
    return 0;
}
