#pragma force_active on
extern void* fn_8022EFF8(int);
extern void fn_80242908(void*);

int fn_80245A40(void* arg0, unsigned short arg1) {
    void* ptr;
    unsigned char* p;

    if (arg0 == 0) {
        ptr = fn_8022EFF8(2);
        if (ptr == 0) {
            return 0;
        }
    } else {
        ptr = arg0;
    }

    p = (unsigned char*)ptr;
    *(unsigned short*)(p + 2) = 5;
    *(unsigned short*)(p + 4) = 0;
    *(unsigned char*)(p + 8) = 4;
    *(unsigned char*)(p + 9) = 8;
    *(unsigned char*)(p + 0xA) = 2;
    *(unsigned char*)(p + 0xB) = (unsigned char)arg1;
    *(unsigned char*)(p + 0xC) = (unsigned char)(arg1 >> 8);
    fn_80242908(ptr);
    return 1;
}
