#pragma force_active on
extern "C" void fn_802FB418(void* a, char* self, short value) {
    int count = *(unsigned char*)(self + 0x21);
    char* p = self;
    for (int i = 0; i < count; i++) {
        if (*(unsigned short*)(p + 2) == 0xFFFF) {
            *(unsigned short*)(self + i * 4 + 2) = (unsigned short)value;
            return;
        }
        p += 4;
    }
}
