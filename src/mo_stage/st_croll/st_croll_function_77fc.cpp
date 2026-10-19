#pragma force_active on
struct ResourceBase {
    unsigned char padding[0xA0];
};

struct Resource : ResourceBase {
    virtual void destroy(int);
};

struct Handle {
    Resource *resource;
};

extern "C" void __dl__FPv(void *);

extern "C" void *fn_90_77FC(Handle *handle, int deleteFlag) {
    if (handle != 0) {
        Resource *resource = handle->resource;
        if (resource != 0) {
            if (resource != 0) {
                resource->destroy(1);
            }
            handle->resource = 0;
        }
        if (deleteFlag > 0) {
            __dl__FPv(handle);
        }
    }
    return handle;
}
