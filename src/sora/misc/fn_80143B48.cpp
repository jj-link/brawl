#pragma force_active on

extern "C" void* memset(void*, int, unsigned long);
extern "C" void fn_80143C48(void*, int);
extern "C" const float lbl_805A2B50;

struct Entry {
    unsigned char flags;
    unsigned char a, b, pad3;
    float value;
    unsigned short c;
    unsigned char padA[6];
    unsigned short d;
    unsigned short pad12;
    int e, f;
    unsigned char data[0xE30];
    unsigned char padE4C[4];
};

extern "C" void fn_80143B48(void* arg) {
    float value = lbl_805A2B50;
    Entry* p = (Entry*)((char*)arg + 0x44);
    unsigned int i = 0;
    char* self = (char*)arg;

    do {
        p->f = 0;
        p->e = 0;
        memset(p->data, 0, 0xE30);
        p->flags &= ~0xFF;
        p->a = 0;
        p->b = 0;
        p->value = value;
        p->c = 0;
        p->d = 0;
        p->f = 0;
        p->e = 0;
        memset(p->data, 0, 0xE30);
        ++i;
        ++p;
    } while (i < 4);

    char* base = self + 0x3994;
    *(int*)(self + 0x3988) = 0;
    *(int*)(self + 0x3984) = 0;
    *(void**)(self + 0x398C) = base;
    *(void**)(self + 0x3998) = base + 0x390;
    *(void**)(self + 0x3D28) = base + 0x720;
    *(void**)(self + 0x40B8) = base + 0xAB0;
    *(int*)(self + 0x4448) = 0;
    fn_80143C48(self, 0);
}
