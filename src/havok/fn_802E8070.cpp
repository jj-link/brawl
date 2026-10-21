#pragma force_active on
extern "C" int fn_802E8070(char* self, unsigned int key) {
    int count = *(int*)(self + 0x94);
    int i;
    for (i = 0; i < count; i++) {
        unsigned int v = *(unsigned int*)(*(char**)(self + 0x90) + i * 4);
        if (v == key) {
            return 0x01000000;
        }
    }
    return 0;
}
