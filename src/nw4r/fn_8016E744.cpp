#pragma force_active on
extern "C" {
void* fn_8016E744(void* self, int idx) {
    int offset = *(int*)self;
    unsigned char* base = (unsigned char*)self + offset;
    unsigned short count = *(unsigned short*)(base + 4);
    if ((unsigned int)idx >= (unsigned int)count) return 0;
    unsigned char* ptr = base + 8;
    int i = 0;
    for (int ctr = count; ctr > 0; ctr--) {
        int len = (ptr[0] << 8) + ptr[1];
        ptr += 2;
        ptr += len;
        int a = ptr[2];
        int b = ptr[1];
        int c = ptr[0];
        int d = ptr[3];
        int val = (c << 24) + (b << 16) + (a << 8) + d;
        ptr += 8;
        if (i == idx) return (void*)(base + val);
        i++;
    }
    return 0;
}
}
