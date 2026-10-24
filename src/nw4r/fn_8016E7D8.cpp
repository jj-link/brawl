#pragma force_active on
struct S {
    unsigned char pad0[8];
    unsigned int f8;
    unsigned char padC[0xC];
    unsigned int f18;
    unsigned int f1C;
};

extern "C" void fn_8016E7D8(unsigned char* arg) {
    unsigned char* base = arg + *(int*)arg;
    unsigned char* p = base + 8;
    int i = 0;
    while (i < *(unsigned short*)(base + 4)) {
        i++;
        int len = (p[0] << 8) + p[1];
        p += 2;
        unsigned char* data = p;
        p += len;
        int target = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];
        p += 8;
        S* t = (S*)(base + target);
        *(unsigned int*)(base + target) = (unsigned int)data;
        t->f18 = (unsigned int)(t + 1);
        t->f1C = t->f18 + t->f8;
    }
}
