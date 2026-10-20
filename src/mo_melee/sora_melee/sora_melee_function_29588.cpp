#pragma force_active on
typedef unsigned long long u64;

struct Result {
    unsigned int padding[6];
    u64 value;
    unsigned int tail[4];
};

struct Resource {
    unsigned int unused;
    void* data;
};

struct Interface {
    virtual ~Interface();
    virtual Resource* get();
};

struct Object {
    unsigned int padding[10];
    Interface* resource;
};

extern "C" void fn_801341D8(void*, Result*);

extern "C" u64 fn_27_29588(const Object& self) {
    Result result;
    fn_801341D8(self.resource->get()->data, &result);
    return result.value;
}
