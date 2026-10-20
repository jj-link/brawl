#pragma force_active on
extern "C" {
char* strcpy(char*, const char*);
int sprintf(char*, const char*, ...);

extern void* g_GameGlobal;
void* fn_8004D138(void*, unsigned int);
void fn_8006BCA8(char*, const void*);
void fn_8006BAB0(char*, int, int, int);

extern int lbl_10_rodata_8A8[];
extern char lbl_10_data_E20[];
extern int lbl_16_data_28;
extern int lbl_16_data_30;
}

struct Data {
    int kind;
    char pad[0x4c];
    char name[0x20];
    unsigned short ids[1];
};

extern "C" int fn_10_1CD6C(Data* self, char* out, int n) {
    int result = -1;

    switch (self->kind) {
    case 0:
        if (n <= 0) {
            strcpy(out, self->name);
        } else {
            void* p = fn_8004D138(g_GameGlobal, self->ids[n - 1]);
            fn_8006BCA8(out, (char*)p + 0xe0);
        }
        break;

    case 1:
        result = lbl_10_rodata_8A8[n];
        break;

    case 2: {
        out[0] = 0;
        char buf[32];
        sprintf(buf, lbl_10_data_E20, n * 10);
        for (char* p = buf; *p; ++p)
            fn_8006BAB0(out, lbl_16_data_28, *p - '0', 1);
        fn_8006BAB0(out, lbl_16_data_30, 0, 1);
        break;
    }

    case 3:
        if (n == 0) {
            out[0] = 0;
            char buf[32];
            sprintf(buf, lbl_10_data_E20, 1);
            for (char* p = buf; *p; ++p)
                fn_8006BAB0(out, lbl_16_data_28, *p - '0', 1);
        } else {
            out[0] = 0;
            char buf[32];
            sprintf(buf, lbl_10_data_E20, n * 10);
            for (char* p = buf; *p; ++p)
                fn_8006BAB0(out, lbl_16_data_28, *p - '0', 1);
        }
        break;
    }

    return result;
}
