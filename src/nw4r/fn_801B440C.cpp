#pragma force_active on

struct SubObj {
    void* vtable;
    char pad[0x14];
    unsigned int unk18;
    unsigned int unk1C;
    unsigned int unk20;
};

struct MainObj {
    void* vtable;
    char pad04[0xC8];
    int unkCC;
    char padD0[0x18];
    int unkE8;
};

extern "C" {
void* fn_80204E5C(void*, unsigned int);
void fn_801AC13C(void*, int, int, int);
void fn_801ADDD4(void*, int, int, int);
void* fn_8018ECCC(void*, const char*);
extern int lbl_80466450[];
extern int lbl_804664B8[];
extern char lbl_8059E930;
extern char lbl_8059E938;

void* fn_801B440C(int arg0, int* arg1, int arg2, int arg3, int* arg4, int arg5) {
    unsigned int size2;
    unsigned int size;
    int a3x4;
    int size3;
    int sp8;
    void* result = 0;

    size = (unsigned int)(arg2 * 4 + 0xEF) & 0xFFFFFFFC;
    size2 = (size + (unsigned int)(arg3 * 8) + 3) & 0xFFFFFFFC;
    a3x4 = arg3 * 4;
    size3 = (int)(size2 + 0x27) & 0xFFFFFFFC;

    if (arg1 != 0) {
        *arg1 = size3;
    }
    if (arg0 != 0) {
        result = fn_80204E5C((void*)arg0, size3);
        if (result == 0) {
            return 0;
        }

        char* base = (char*)result + size;
        SubObj* sub = (SubObj*)((char*)result + size2);
        if (sub != 0) {
            sp8 = *arg4;
            fn_801ADDD4(
                sub,
                (int)base,
                (int)(base + a3x4),
                arg3
            );
            sub->vtable = (void*)lbl_80466450;
            sub->unk18 = (unsigned int)sp8;
            sub->unk1C = (unsigned int)(sp8 != 0
                ? fn_8018ECCC(&sp8, &lbl_8059E930)
                : 0);
            sub->unk20 = (unsigned int)(sp8 != 0
                ? fn_8018ECCC(&sp8, &lbl_8059E938)
                : 0);
        }

        if (result != 0) {
            MainObj* main = (MainObj*)result;
            fn_801AC13C(result, arg0, (int)((char*)result + 0xEC), arg2);
            main->vtable = (void*)lbl_804664B8;
            main->unkE8 = (int)sub;
            main->unkCC = main->unkCC & 0x9FFFFFFF;
        }
    }

    return result;
}
}
