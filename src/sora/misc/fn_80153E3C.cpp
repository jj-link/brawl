#pragma force_active on
extern "C" {
void __dl__FPv(void* p);
void free__13gfHeapManagerFPv(void* p);

void* fn_80153E3C(void* self, int flag) {
    if (self != 0) {
        char* cursor = (char*)self;
        for (unsigned int i = 0; i < *(unsigned int*)((char*)self + 0xB4); i++) {
            if (*(void**)(cursor + 0x20) != 0) {
                free__13gfHeapManagerFPv(*(void**)(cursor + 0x20));
                *(void**)(cursor + 0x20) = 0;
            }
            cursor += 0x24;
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
