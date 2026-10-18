#pragma force_active on
extern "C" {

typedef unsigned char u8;
typedef int s32;

void exit__6gfTaskFv(void*);

int fn_16_5438(void* self) {
    u8* base = (u8*)self;
    void* p = *(void**)(base + 0x45c);
    int value;
    if (*(int*)((u8*)p + 0x104) != 3) {
        value = 0;
    } else {
        value = 2;
        if (*(u8*)((u8*)p + 0x100) != 0) {
            value = 1;
        }
        exit__6gfTaskFv(p);
        *(void**)(base + 0x45c) = 0;
    }
    int result;
    if (value == 0) {
        result = *(int*)(base + 0x9c);
    } else {
        if (*(u8*)(base + 0x451) == 0 && *(u8*)(base + 0x450) == 0) {
            result = 0xe;
        } else {
            result = 0xf;
        }
    }
    return result;
}

}
