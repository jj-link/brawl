#pragma force_active on
extern void fn_8036EE44(void* self);

void fn_8036EEE4(void* self, void* node) {
    unsigned char* s = *(unsigned char**)self;
    unsigned char* n = (unsigned char*)node;
    unsigned char* cur = *(unsigned char**)(s + 0x440);
    unsigned char* prev = 0;

    while (cur != 0) {
        if (cur == n) {
            if (prev == 0) {
                *(unsigned char**)(s + 0x440) = *(unsigned char**)(cur + 0x20);
            } else {
                *(unsigned char**)(prev + 0x20) = *(unsigned char**)(n + 0x20);
            }
            fn_8036EE44(self);
            return;
        }
        prev = cur;
        cur = *(unsigned char**)(cur + 0x20);
    }
}
