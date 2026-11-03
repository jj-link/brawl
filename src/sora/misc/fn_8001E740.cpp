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
extern char lbl_80421380[];
void OSReport(const char*, ...);
void fn_8001B9E8(int);
int fn_803C3048(const char*, int);
char* fn_8020D38C(char*);

void fn_8001E740(Foo* arg0) {
    char buf_name[0x80];
    char buf_path[0x80];
    char buf_tmp[0x80];

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

    int result = fn_803C3048(buf_path, arg0->field8);
    if (result != 0) {
        OSReport(lbl_80421380, buf_path, arg0->field8, result);
        fn_8001B9E8(result);
        result = 8;
    } else {
        result = 0;
    }
    arg0->status = (unsigned int)result;
}

}