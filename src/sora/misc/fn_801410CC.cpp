#pragma force_active on
extern "C" void* fn_801410CC(void* self, int index) {
    void* root = *(void**)((char*)self + 0x454);
    if (root == 0) return 0;

    char* base = (char*)root;
    if (*(unsigned char*)(base + index * 0x18 + 0x14) == 0) return 0;

    unsigned short counter = *(unsigned short*)(base + 0xe);
    char* node = base;

    while (true) {
        char* next = *(char**)(node + 0x8);
        if (next == 0) return (void*)node;

        counter++;
        if (*(unsigned char*)(next + index * 0x18 + 0x14) == 0) return (void*)node;

        unsigned short nextIdx = *(unsigned short*)(next + 0xe);
        if (nextIdx != counter) return (void*)node;

        node = next;
    }
}