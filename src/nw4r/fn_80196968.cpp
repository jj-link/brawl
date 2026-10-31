#pragma force_active on

struct Resource {
    char* ptr;
    Resource() {}
    Resource(char* p) : ptr(p) {}
};

struct Handle {
    char* ptr;
};

extern "C" int fn_8018CFAC(Resource*, const Resource*, void*);
extern char lbl_80465BE0[0x20];

extern "C" int fn_80196968(const Handle* self, int unused, void* arg)
{
    char* base = self->ptr;
    int offset = *(int*)(base + 0x10);
    Resource data;
    data.ptr = offset ? base + offset : 0;
    Resource value(lbl_80465BE0);
    char* r = (char*)fn_8018CFAC(&data, &value, arg);

    if (r != 0) {
        if (((unsigned int)(-(int)r | (int)r) >> 31) != 0) {
            return *(int*)(r + 4);
        }
        return 0;
    }
    return 0;
}
