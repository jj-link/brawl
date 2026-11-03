#include <gf/gf_file_io.h>
#pragma force_active on
extern "C" {
unsigned int strlen(const char*);
char* strncpy(char*, const char*, unsigned int);
char* strcat(char*, const char*);
int fn_8001B7F8(const char*);
int fn_8001F390(void*);
int fn_8001F4B0(void*);
int fn_801F5F08(const char*);
int fn_801F6210(int, void*);
extern int lbl_8059C530;
extern char* lbl_804211C0[];
extern char lbl_8059C56C[4];
}
struct S {
    const char* p;
    int a, b, c, d;
    unsigned r : 8;
    unsigned x : 8;
    unsigned y : 16;
};
struct B { unsigned char pad[0x15]; unsigned char x : 8; };
extern "C" int fn_8001F0D4(S* self) {
    char name[128];
    char localized[128];
    char path[128];
    int info[16];
    int type = fn_8001B7F8(self->p);
    const char* s = self->p;
    unsigned int n = strlen(s);
    const char* q = s;
    for (unsigned int i = 0; i < n; i++) {
        if (*q == ':') {
            strncpy(name, q + 1, 128);
            goto copied;
        }
        q++;
    }
    strncpy(name, s, 128);
copied:
    S local;
    ((int*)&local)[0] = ((int*)self)[0];
    ((int*)&local)[1] = ((int*)self)[1];
    ((int*)&local)[2] = ((int*)self)[2];
    ((int*)&local)[3] = ((int*)self)[3];
    ((int*)&local)[4] = ((int*)self)[4];
    ((int*)&local)[5] = ((int*)self)[5];
    local.p = name;
    local.b = 0;
    int status = 17;
    if (type == 2) goto nand;
    if (type < 2) {
        if (type == 0) goto common;
        if (type >= 0) goto common;
        goto done;
    }
    if (type == 4) goto vf;
    if (type >= 4) goto done;
    goto sd;
common: {
        status = 17;
        int size;
        int length;
        const char* p = local.p;
        fn_8001B7F8(p);
        unsigned int len = strlen(p);
        const char* t = p;
        for (unsigned int i = 0; i < len; i++) {
            if (*t == ':') {
                strncpy(path, t + 1, 128);
                goto copied2;
            }
            t++;
        }
        strncpy(path, p, 128);
copied2:
        length = strlen(path);
        const char* end = path + length;
        for (int i = length; i != 0; i--) {
            if (*end == '.') {
                strncpy(localized, path, length);
                localized[length] = 0;
                strcat(localized, lbl_804211C0[lbl_8059C530]);
                strcat(localized, path + length);
                goto localized_done;
            }
            end--;
            length--;
        }
        strncpy(localized, path, 128);
        strcat(localized, lbl_8059C56C);
localized_done:
        size = -1;
        int file = fn_801F5F08(localized);
        if (file < 0) file = fn_801F5F08(path);
        if (file >= 0) {
            fn_801F6210(file, info);
            size = (info[13] + 31) & ~31;
        }
        if (size >= 0) status = 0;
        goto done;
    }
    nand: status = fn_8001F390(&local); goto done;
    sd: status = gfFileIO::checkFileSD((gfFileIORequest*)&local); goto done;
    vf:
        ((B*)&local)->x = ((const unsigned char*)self->p)[2] - '0';
        status = fn_8001F4B0(&local);
        goto done;
    done:
    self->r = status;
    if (status == 0) self->b = local.b;
    return status;
}