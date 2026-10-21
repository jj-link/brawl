#pragma force_active on

extern "C" void* fn_27_21FD30(void*, int);

extern "C" void* fn_27_1F2D6C(char* p, int key, int arg) {
    if (p + 0x4c) {
        int i;
        char* cur = p;
        for (i = 0; i < 14; cur += 4, ++i) {
            char* o = *(char**)(cur + 0x4c);
            if (o && (*(unsigned short*)(o + 0x3c) & 0x8000) &&
                key == *(int*)(o + 0x30)) {
                p = *(char**)(p + 0x4c + i * 4);
                p = *(char**)(p + 0x94);
                goto done;
            }
        }
    }
    p = 0;
done:
    if (p)
        return fn_27_21FD30(p, arg);
    return 0;
}
