#pragma force_active on
typedef unsigned long u32;

extern "C" void* getNode__6utListFUl(void*, u32);
extern "C" int fn_80015DAC(int);

static inline char* findNode(char* object, u32 id) {
    if (id != 0xFFFF) {
        char* node = (char*)getNode__6utListFUl(object + 0x28, 0);
        while (node != 0) {
            if (*(u32*)(node + 0xC) == id) {
                return node;
            }
            node = *(char**)node;
        }
    }
    return 0;
}

extern "C" int fn_80045DC0(char* object, u32 id, int* output) {
    if (id != 0xFFFF) {
        char* node = findNode(object, id);
        if (node != 0) {
            int result = fn_80015DAC(*(int*)(node + 0x14));
            if (output != 0) {
                *output = result;
            }
            int ret = 2;
            if (result == 0) {
                ret = 1;
            }
            return ret;
        }
    }
    return 0;
}
