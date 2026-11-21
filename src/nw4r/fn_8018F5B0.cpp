#pragma force_active on
extern "C" void fn_80192080(void*);
static inline void release(unsigned char** self) {
    unsigned char* base = *self;
    int offset = *(int*)(base + 0x28);
    unsigned i;
    unsigned count;
    unsigned char* dict;
    if (offset != 0) {
        dict = base + offset;
    } else {
        dict = 0;
    }
    if (dict != 0) {
        count = *(unsigned*)(dict + 4);
    } else {
        count = 0;
    }
    i = 0;
    unsigned entryOffset = 0;
    if (count != 0) {
        for (; i < count; ++i, entryOffset += 0x10) {
            base = *self;
            offset = *(int*)(base + 0x28);
            dict = offset ? base + offset : 0;
            unsigned char* data = dict
                ? (*(int*)(dict + entryOffset + 0x24)
                    ? dict + *(int*)(dict + entryOffset + 0x24) : 0)
                : 0;
            fn_80192080(&data);
        }
    }
}

extern "C" void fn_8018F5B0(unsigned char** self) {
    release(self);
}
