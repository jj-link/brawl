#pragma force_active on
// The classes and the object this function's exception table needs, written by decomp-orchestrator.

class Class_803F0B20 {
public:
    void* base;
    unsigned long size;
    unsigned long max;
    void (*dtorFn)(void*, int);
    unsigned long count;

    ~Class_803F0B20() {
        if (count < max && dtorFn != 0) {
            char* p = (char*)base + size * count;
            while (count != 0) {
                p = (char*)p - size;
                dtorFn(p, -1);
                count = count - 1;
            }
        }
    }
};

extern "C" void* __construct_new_array(void* block, void (*ctor)(void*, int), void (*dtor)(void*, int), unsigned long size, unsigned long count) {
    void* result = block;
    if (block != 0) {
        *(unsigned long*)block = size;
        *(unsigned long*)((char*)block + 4) = count;
        result = (char*)block + 0x10;
        if (ctor != 0) {
            Class_803F0B20 local;
            local.base = result;
            local.size = size;
            local.max = count;
            local.dtorFn = dtor;
            local.count = 0;
            char* p = (char*)result;
            while (local.count < count) {
                ctor(p, 1);
                p = p + size;
                local.count = local.count + 1;
            }
        }
    }
    return result;
}
