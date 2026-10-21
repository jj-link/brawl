#pragma force_active on
typedef unsigned int u32;

extern "C" {
void* fn_8018BC7C(char* self, u32 key) {
    char* node = *(char**)(self + 4);
    while (node != self + 4) {
        if (key == *(u32*)(node + 8)) {
            return node;
        }
        node = *(char**)node;
    }
    return 0;
}
}
