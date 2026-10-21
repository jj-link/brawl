#pragma force_active on
extern void* fn_801E087C(void* self, int arg);

void fn_801E0A30(void* self, int val) {
    void* ptr = self;
    for (;;) {
        if (*(int*)((unsigned char*)ptr + 0x2CC) > 0 || *(int*)((unsigned char*)ptr + 0x2D0) <= val)
            break;
        ptr = fn_801E087C(ptr, val);
        if (ptr == 0)
            break;
    }
}
