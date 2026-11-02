#pragma force_active on
// The classes and the object this function's exception table needs, written by decomp-orchestrator.

class Class_803F0B20 {
public:
    void* ptr;
    unsigned long size;
    unsigned long count;
    void (*dtor)(void*, int);
    unsigned long i;
    Class_803F0B20(void* p, void (*d)(void*, int), unsigned long s, unsigned long c)
        : ptr(p), size(s), count(c), dtor(d), i(0) {}
    ~Class_803F0B20() {
        if (i < count && dtor) {
            char* p = (char*)ptr + size * i;
            while (i != 0) {
                p -= size;
                dtor(p, -1);
                i--;
            }
        }
    }
};

extern "C" void __construct_array(void* ptr, void (*ctor)(void*, int), void (*dtor)(void*, int), unsigned long size, unsigned long count) {
    {
        Class_803F0B20 a(ptr, dtor, size, count);
        char* p = (char*)ptr;
        while (a.i < count) {
            ctor(p, 1);
            p += size;
            a.i++;
        }
    }
}
