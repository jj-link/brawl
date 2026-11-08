#pragma force_active on

typedef signed int s32;
typedef unsigned int u32;

class Class_803F0B20 {
public:
    char* p;
    s32 size;
    s32 count;
    void (*dtor)(void*, s32);
    u32 n;

    Class_803F0B20() {}

    ~Class_803F0B20() {
        if (n < (u32)count && dtor != 0) {
            char* ptr = p + size * n;
            while (n != 0) {
                ptr -= size;
                dtor(ptr, -1);
                n--;
            }
        }
    }
};

extern "C" void __construct_array(
    char* array,
    void (*ctor)(void*, s32),
    void (*dtor)(void*, s32),
    s32 size,
    s32 count
) {
    Class_803F0B20 local0;
    local0.p = array;
    local0.size = size;
    local0.count = count;
    local0.dtor = dtor;
    local0.n = 0;

    char* ptr = array;
    while (local0.n < (u32)count) {
        ctor(ptr, 1);
        ptr += size;
        local0.n++;
    }
}
