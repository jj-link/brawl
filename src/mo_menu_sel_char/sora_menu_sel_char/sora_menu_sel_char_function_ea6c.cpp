#pragma force_active on
extern "C" {
int fn_10_15244(void* entry, void* a, void* c, void* d);
}

extern "C" int fn_10_EA6C(void* obj, void* a, int* out, void* c, void* d) {
    void* base = obj;
    char* p = (char*)obj;
    int index = 0;
    for (; index < *(int*)((char*)base + 0x648); index++) {
        int r = fn_10_15244(*(void**)(p + 0x44), a, c, d);
        if (r != 0) {
            *out = index;
            return r;
        }
        p += 4;
    }
    return 0;
}
