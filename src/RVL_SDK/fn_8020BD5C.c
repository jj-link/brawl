#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Info {
    char pad[8];
    char path[128];
    u8 access;
    u8 stage;
} Info;

typedef struct Block {
    char pad[4];
    void *callback;
    Info *info;
    char pad2[0x70];
    int state;
    void *buffer;
    u32 size;
    char pad3[0x30];
    int extra;
} Block;

extern int fn_8020CAD4(void);
extern int fn_8020CA48(char *);
extern int fn_8020CAEC(void);
extern void fn_8020CC4C(char *, const char *);
extern int fn_80214E80(char *, int, void (*)(void), void *);
extern int fn_80213FC8(const char *, int, int, int, int, void (*)(void), void *);
extern void fn_8020C2B4(void);
extern void fn_8020BEC4(void);
extern char lbl_8047C090[];

int fn_8020BD5C(const char *path, Info *info, u8 mode, void *buffer,
                u32 size, void *callback, Block *block, int flag, int extra)
{
    int result;

    if (fn_8020CAD4() == 0)
        return -128;

    if (extra != 0 && (size & 0x3fff))
        return -8;

    info->access = mode;
    info->stage = 0;
    block->extra = extra;
    fn_8020CC4C(info->path, path);

    if (flag == 0 && fn_8020CA48(info->path) != 0)
        return -1;

    if (mode == 1) {
        block->info = info;
        block->callback = callback;
        if (fn_80214E80(info->path, 1, fn_8020C2B4, block) == 0)
            return 0;
        return fn_8020CAEC();
    }

    if ((u8)(mode + 0xfe) <= 1) {
        result = 0;
        block->info = info;
        block->callback = callback;
        block->state = 0;
        block->buffer = buffer;
        block->size = size;
        if (fn_80213FC8(lbl_8047C090, 0, 3, 3, 3, fn_8020BEC4, block) == 0)
            result = 0;
        else
            result = fn_8020CAEC();
        return result;
    }

    return -8;
}
