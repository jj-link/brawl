#pragma force_active on
extern "C" {

struct Foo {
    char* str;
    int field4;
    int field8;
    int fieldC;
    int field10;
    unsigned int status : 8;
    unsigned int pad : 24;
};

unsigned int strlen(const char*);
char* strncpy(char*, const char*, unsigned int);
char* strcat(char*, const char*);
int strncmp(const char*, const char*, unsigned int);
extern char lbl_8059C57C[5];
extern char lbl_804213B8[];
extern unsigned char lbl_805A14BC;
extern unsigned char lbl_805A14BD;
void OSReport(const char*, ...);
void fn_8001B9E8(int);
int fn_803C31B4(unsigned char*, const char*);
char* fn_8020D38C(char*);

void fn_8001E86C(Foo* arg0) {
    unsigned char drive[2];
    char buf_name[0x80];
    char buf_path[0x80];
    char buf_tmp[0x80];

    drive[0] = lbl_805A14BC;
    drive[1] = lbl_805A14BD;

    const char* str = arg0->str;
    unsigned int len = strlen(str);
    const char* p = str;
    unsigned int i;

    for (i = 0; i < len; i++) {
        if (*p == ':') {
            strncpy(buf_name, p + 1, 0x80);
            goto done;
        }
        p++;
    }
    strncpy(buf_name, str, 0x80);

done:
    buf_path[0] = 0;
    if (strncmp(buf_name, lbl_8059C57C, 4) == 0) {
        strcat(buf_path, buf_name);
    } else {
        fn_8020D38C(buf_tmp);
        strncpy(buf_path, buf_tmp, 0x40);
        strcat(buf_path, buf_name);
    }

    drive[0] = drive[0] + ((unsigned char*)arg0)[0x15];
    int result = fn_803C31B4(drive, buf_path);
    if (result != 0) {
        OSReport(lbl_804213B8, drive, buf_path, result);
        fn_8001B9E8(result);
        if (result == 0xb005) {
            result = 10;
        } else {
            result = 9;
        }
    } else {
        result = 0;
    }
    arg0->status = (unsigned int)result;
}

}
