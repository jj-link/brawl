#pragma force_active on
extern void *__peReg;

typedef unsigned short u16;

u16 GXReadDrawSync(void) {
    return *(u16 *)((char *)__peReg + 0xE);
}
