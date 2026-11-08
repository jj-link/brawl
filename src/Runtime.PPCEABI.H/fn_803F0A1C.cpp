#pragma force_active on
typedef unsigned int u32;
typedef void (*Proc)(void*, int);

class Class_803F0B20 {
public:
    char* p;
    u32 size;
    u32 n;
    Proc dtor;
    u32 i;

    Class_803F0B20(void* array, u32 elementsize, u32 nelements, Proc destructor) {
        p = (char*)array;
        size = elementsize;
        n = nelements;
        dtor = destructor;
        i = 0;
    }
    ~Class_803F0B20() {
        if (i < n && dtor) {
            char* ptr = p + size * i;
            while (i != 0) {
                ptr -= size;
                dtor(ptr, -1);
                i--;
            }
        }
    }
};

extern "C" void* __construct_new_array(
    void* block, Proc ctor, Proc dtor, u32 size, u32 n
) {
    char* ptr = (char*)block;
    if (ptr != 0) {
        ((u32*)ptr)[0] = size;
        ((u32*)ptr)[1] = n;
        ptr += 16;
        if (ctor) {
            Class_803F0B20 pad(ptr, size, n, dtor);
            char* p = ptr;
            for (pad.i = 0; pad.i < n; pad.i++, p += size) {
                ctor(p, 1);
            }
        }
    }
    return ptr;
}
