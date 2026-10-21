#pragma force_active on
typedef unsigned char u8;

extern void fn_8021A118(void*, void*);
extern void fn_8021A180(void*, void*);

void fn_8027A640(u8* self) {
    fn_8021A118(*(void**)self, *(void**)(self + 0x28));
    *(void**)(self + 0x28) = 0;
    fn_8021A180(*(void**)self, *(void**)(self + 0x2C));
    *(void**)(self + 0x2C) = 0;
}
