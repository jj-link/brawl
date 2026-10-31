#pragma force_active on

struct Resource {
    void* ptr;
    Resource(void* p) : ptr(p) {}
};

extern "C" int fn_8018CFAC(void*, Resource, void*);
extern char lbl_80465C20[0x20];

extern "C" int fn_80196CD0(const void* arg0, void* arg1, void* arg2)
{
    char* base = *(char**)arg0;
    int offset = *(int*)(base + 0x10);
    Resource data(offset ? (void*)(base + offset) : 0);
    int res = fn_8018CFAC(&data.ptr, Resource(lbl_80465C20), arg2);

    if (res != 0) {
        if (((unsigned int)(-res | res) >> 31) != 0) {
            return *(int*)((char*)res + 4);
        }
        return 0;
    }
    return 0;
}
