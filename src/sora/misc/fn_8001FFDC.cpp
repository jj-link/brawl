#include <gf/gf_file_io.h>
#include <string.h>
#pragma force_active on

extern "C" {
int fn_8001B7F8(const char*);
int fn_801F5F08(const char*);
int fn_801F6210(int, void*);

extern int lbl_8059FFD8;
extern int lbl_8059C530;
extern char* lbl_804211C0[];
extern char lbl_8059C56C[4];
}

int gfFileIO::getFileSize(const char* s) {
    char name[128];
    char path[128];
    char localized[128];
    char path2[128];
    char localized2[128];
    int info[15];
    int info2[15];

    const int type = fn_8001B7F8(s);
    int fallback = lbl_8059FFD8;
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
    int size = (int)s;
    switch (type) {
    case 0:
        size = -1;
        break;

    case 1: {
        fn_8001B7F8(name);
        unsigned int len = strlen(name);
        const char* p = name;

        for (unsigned int i = 0; i < len; i++) {
            if (*p == ':') {
                strncpy(path, p + 1, 128);
                goto copied2;
            }
            p++;
        }
        strncpy(path, name, 128);

    copied2:
        int count = strlen(path);
        int length = count;
        const char* end = path + length;
        for (int i = count; i != 0; i--) {
            if (*end == '.') {
                char* dest = localized;
                strncpy(dest, path, length);
                dest[length] = 0;
                strcat(dest, lbl_804211C0[lbl_8059C530]);
                strcat(dest, path + length);
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
        if (file < 0)
            file = fn_801F5F08(path);
        if (file >= 0) {
            fn_801F6210(file, info);
            size = (info[13] + 31) & ~31;
        }
        break;
    }
    }

    int next = fallback;
    if (type == fallback) {
        if (type == 1)
            next = 0;
        else if (type == 0)
            next = 1;
    }

    if (size < 0) {
        switch (next) {
        case 0:
            size = -1;
            break;

        case 1: {
            fn_8001B7F8(name);
            unsigned int len = strlen(name);
            const char* p = name;

            for (unsigned int i = 0; i < len; i++) {
                if (*p == ':') {
                    strncpy(path2, p + 1, 128);
                    goto copied3;
                }
                p++;
            }
            strncpy(path2, name, 128);

        copied3:
            int count = strlen(path2);
            int length = count;
            const char* end = path2 + length;
            for (int i = count; i != 0; i--) {
                if (*end == '.') {
                    strncpy(localized2, path2, length);
                    localized2[length] = 0;
                    strcat(localized2, lbl_804211C0[lbl_8059C530]);
                    strcat(localized2, path2 + length);
                    goto localized_done2;
                }
                end--;
                length--;
            }
            strncpy(localized2, path2, 128);
            strcat(localized2, lbl_8059C56C);

        localized_done2:
            size = -1;
            int file = fn_801F5F08(localized2);
            if (file < 0)
                file = fn_801F5F08(path2);
            if (file >= 0) {
                fn_801F6210(file, info2);
                size = (info2[13] + 31) & ~31;
            }
            break;
        }

        case 6:
            size = 1;
            break;
        }
    }

    return size;
}
