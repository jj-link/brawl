#pragma force_active on
extern "C" {
int fn_100_9CE4();
}

extern "C" unsigned int fn_100_9CF0(char* self, int unused, int idx1, int idx2) {
    int k = fn_100_9CE4();
    char* a = (char*)((unsigned int)k << 3);
    a = (char*)((int)self - 0x10000 + (int)a);
    char* b = a + ((unsigned int)idx1 << 2);
    char* table = *(char**)(b - 0x75c8);
    return *(unsigned int*)(table + ((unsigned int)idx2 << 2));
}
