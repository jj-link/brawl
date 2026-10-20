#pragma force_active on
typedef unsigned char u8;

extern "C" {
int fn_68_1EC8(void* self) {
    char* base = (char*)self;
    char* obj = *(char**)(base + 0x9c);
    if (obj == 0) {
        return 0xff;
    }
    int i = 0;
    u8 count = *(u8*)(obj + 0x28);
    for (; (u8)i != count; i++) {
        char* entry = *(char**)(base + 0x428) + (u8)i * 0x28;
        if (*(u8*)(entry + 0x24) == 0xd) {
            return i;
        }
    }
    return 0xff;
}
}
