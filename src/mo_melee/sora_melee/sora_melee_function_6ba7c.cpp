#pragma force_active on
struct utList {
    void* getNode(unsigned long index);
};

extern "C" void* fn_27_6F30C(void* node);

extern "C" int fn_27_6BA7C(char* self, int id) {
    char* node = (char*)((utList*)(self + 0x14))->getNode(0);
    while (node != 0) {
        char* data = *(char**)(node + 0xc);
        int field = *(int*)(data + 0x30);
        if (id == ((field >> 1) & 0x7F)) {
            char* acc = (char*)fn_27_6F30C(node);
            char* d = *(char**)(acc + 0x44);
            char* m = *(char**)(d + 0x8);
            return *(int*)(m + 0x28);
        }
        node = *(char**)node;
    }
    return -1;
}
