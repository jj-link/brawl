#include <types.h>
#pragma force_active on

extern "C" {
void fn_800B9488(void*, u32, u32);
void setFontColor__5MuMsgFUlUcUcUcUc(void*, u32, u8, u8, u8, u8);
void printIndex__5MuMsgFUlUlPv(void*, u32, u32, void*);
void printf__5MuMsgFUlPCce(void*, u32, const char*, ...);
int fn_8004D6C4(void*, s32, char*);
char* strcpy(char*, const char*);
extern void* g_GameGlobal;
}

struct FnSelf {
    char pad0[0x10C];
    s32 unk10C[2];
    s32 unk114[2];
    s32 unk11C;
    char pad1[0x12C - 0x120];
    void* msg;
    char pad2[0x30E - 0x130];
    char name0[0x15];
    char name1[0x15];
    s32 unk338;
    s32 unk33C;
    char pad3[0x34C - 0x340];
    s32 unk34C;
};

extern "C" void fn_28_870(FnSelf* self, s32 arg1) {
    char buf[0x18];
    s32 base;
    s32 count;
    s32 j;
    s32 m;
    s32 n;
    s32 idx;
    s32 cnt;

    cnt = self->unk11C;
    base = (arg1 == 0) ? 0 : 5;
    count = 4;
    if (cnt < 4) {
        count = cnt;
    }
    if (self->unk114[arg1] == 0) {
        idx = -1;
        while (idx < count) {
            if (idx == -1) {
                if (arg1 == 0) {
                    fn_800B9488(self->msg, 0, 0);
                    setFontColor__5MuMsgFUlUcUcUcUc(self->msg, 0, 0xFF, 0, 0, 0xFF);
                    if (self->unk34C == -1) {
                        printIndex__5MuMsgFUlUlPv(self->msg, 0, 3, 0);
                    } else {
                        printIndex__5MuMsgFUlUlPv(self->msg, 0, 8, 0);
                    }
                } else {
                    fn_800B9488(self->msg, 5, 0);
                    setFontColor__5MuMsgFUlUcUcUcUc(self->msg, 5, 0, 0, 0xFF, 0xFF);
                    printIndex__5MuMsgFUlUlPv(self->msg, 5, 3, 0);
                }
            } else {
                fn_8004D6C4(g_GameGlobal, idx + self->unk114[arg1], buf);
                n = idx + base + 1;
                fn_800B9488(self->msg, n, 1);
                setFontColor__5MuMsgFUlUcUcUcUc(self->msg, n, 0, 0, 0, 0xFF);
                printf__5MuMsgFUlPCce(self->msg, n, buf);
                if (idx + 1 == self->unk10C[arg1]) {
                    if (arg1 == 0) {
                        strcpy(self->name0, buf);
                        self->unk338 = idx + self->unk114[arg1];
                    } else {
                        strcpy(self->name1, buf);
                        self->unk33C = idx + self->unk114[arg1];
                    }
                }
            }
            idx++;
        }
        return;
    }
    j = 0;
    do {
        fn_8004D6C4(g_GameGlobal, (j + self->unk114[arg1]) - 1, buf);
        m = j + base;
        fn_800B9488(self->msg, m, 1);
        setFontColor__5MuMsgFUlUcUcUcUc(self->msg, m, 0, 0, 0, 0xFF);
        printf__5MuMsgFUlPCce(self->msg, m, buf);
        if (j == self->unk10C[arg1]) {
            if (arg1 == 0) {
                strcpy(self->name0, buf);
                self->unk338 = (j + self->unk114[arg1]) - 1;
            } else {
                strcpy(self->name1, buf);
                self->unk33C = (j + self->unk114[arg1]) - 1;
            }
        }
        j++;
    } while (j < 5);
}
