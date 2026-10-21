#pragma force_active on
struct Obj {
    char pad[0x18];
    int offset;
};

struct Resource {
    void* ptr;

    Resource(void* p) : ptr(p) {}
};

extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);

struct Handle {
    Obj* ptr;

    void* get() const {
        int offset = ptr->offset;
        return offset ? (char*)ptr + offset : 0;
    }
};

extern "C" int fn_8018EE80(const Handle* arg0, const Resource* arg1)
{
    Resource data(arg0->get());
    Resource value = *arg1;
    return fn_8018CFAC(&data, &value, value.ptr);
}
