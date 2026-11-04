#pragma force_active on
extern int fn_803AAB58(void*, void*);

int fn_803AA08C(void* arg1, void* dest) {
    unsigned char local[0x70];
    unsigned char* d = (unsigned char*)dest;

    if (fn_803AAB58(arg1, local) != 0) {
        return 7;
    }

    *(unsigned short*)(d + 0x00) = *(unsigned short*)(local + 0x08);
    *(unsigned short*)(d + 0x02) = *(unsigned short*)(local + 0x0C);
    *(unsigned short*)(d + 0x04) = *(unsigned short*)(local + 0x0E);
    d[0x06] = local[0x0A];
    d[0x07] = local[0x0B];
    *(unsigned int*)(d + 0x08) = *(unsigned int*)(local + 0x68);
    *(unsigned int*)(d + 0x0C) = *(unsigned int*)(local + 0x6C);
    *(unsigned int*)(d + 0x10) = *(unsigned int*)(local + 0x44);
    *(unsigned short*)(d + 0x14) = *(unsigned short*)(local + 0x48);
    *(unsigned short*)(d + 0x16) = *(unsigned short*)(local + 0x4A);
    *(unsigned short*)(d + 0x18) = *(unsigned short*)(local + 0x40);
    d[0x1A] = local[0x22];
    *(unsigned int*)(d + 0x1C) = *(unsigned int*)(local + 0x50);
    d[0x20] = local[0x54];
    d[0x21] = local[0x55];
    d[0x22] = local[0x4F];
    *(unsigned short*)(d + 0x24) = *(unsigned short*)(local + 0x56);
    *(unsigned int*)(d + 0x28) = *(unsigned int*)(local + 0x58);
    *(unsigned int*)(d + 0x2C) = *(unsigned int*)(local + 0x5C);
    *(unsigned int*)(d + 0x30) = *(unsigned int*)(local + 0x60);
    *(unsigned int*)(d + 0x34) = *(unsigned int*)(local + 0x64);

    return 0;
}