#pragma force_active on

struct Resource {
    void* ptr;
    Resource() {}
    Resource(void* p) : ptr(p) {}
};

struct Handle {
    char* ptr;
};

extern "C" void* fn_8018CFAC(Resource*, const Resource*, void*);
extern "C" int fn_8018CF30(void**, const char*);
extern char lbl_80465AC0[0x20];

extern "C" int fn_8018DBEC(const Handle* self, const char* name) {
    char* base = self->ptr;
    Resource data;
    Resource value(lbl_80465AC0);
    data.ptr = base + 0x18;
    void* result = fn_8018CFAC(&data, &value, base);
    if (result != 0) {
        void* item = result;
        return fn_8018CF30(&item, name);
    }
    return 0;
}
