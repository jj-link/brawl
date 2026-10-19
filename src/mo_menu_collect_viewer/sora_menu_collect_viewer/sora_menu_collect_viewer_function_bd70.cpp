#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void exit__6gfTaskFv(void*);

extern "C" int fn_6_BD70(char* self) {
    char* task = *(char**)(self + 0x140);
    int ret;
    if (*(s32*)(task + 0x104) == 3) {
        u8 flag = *(u8*)(task + 0x100);
        exit__6gfTaskFv(task);
        *(void**)(self + 0x140) = 0;
        ret = 1;
        if (flag != 0) {
            ret = 12;
        }
    } else {
        ret = *(int*)(self + 0x128);
    }
    return ret;
}
