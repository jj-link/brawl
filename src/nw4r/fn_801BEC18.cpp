#include <types.h>
#include <revolution/DVD/dvdfs.h>
#include <string.h>
#pragma force_active on
extern "C" {
int fn_801F5F08(const char*);
int fn_801F6210(int, DVDFileInfo*);
void fn_801C7130(void*, const void*);
void fn_801C6B8C(void*, void*);
void fn_801C7090(void*, const char*);
extern signed char lbl_805A0590;
extern const u32 lbl_805A5138;

int fn_801BEC18(u8* self, const char* path) {
    char buf[0x68];
    char dir[0x100];
    int file = fn_801F5F08(path);
    if (file < 0) return 0;
    int ok;
    if (!fn_801F6210(file, (DVDFileInfo*)(self + 0x14c))) {
        ok = 0;
    } else {
        self[0x188] = 1;
        if (!lbl_805A0590) {
            lbl_805A0590 = 1;
            *(u32*)&lbl_805A5138 = 0x40;
        }
        void* aligned = (void*)(((u32)buf + 31) & ~31);
        u32 size = lbl_805A5138;
        u32 result = DVDReadPrio((DVDFileInfo*)(self + 0x14c), aligned, size, 0, 2);
        if (result != size) {
            ok = 0;
        } else {
            fn_801C7130(self + 0x108, aligned);
            fn_801C6B8C(self, self + 0x108);
            ok = 1;
        }
    }
    if (!ok) return 0;
    for (int i = strlen(path) - 1; i >= 0; --i) {
        if (path[i] == '/' || path[i] == '\\') {
            strncpy(dir, path, i);
            dir[i] = 0;
            fn_801C7090(self, dir);
            break;
        }
    }
    return 1;
}
}