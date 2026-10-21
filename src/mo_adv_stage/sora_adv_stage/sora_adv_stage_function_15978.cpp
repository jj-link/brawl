#pragma force_active on
extern "C" {
extern char* g_IfAdvMngr;
extern char* g_IfMngr;

void fn_801078D8(char*);
void fn_800DCF38(char*, int);
void fn_800E3684(char*, int);

void fn_40_15978(int unused, int arg, int flag)
{
    if (g_IfAdvMngr != 0) {
        fn_801078D8(g_IfAdvMngr);
    }

    char* manager = g_IfMngr;
    if (manager == 0) {
        return;
    }

    if (flag == 0) {
        fn_800DCF38(manager, arg);
        return;
    }

    if (arg == 0) {
        if (*(unsigned int*)(manager + 0x50) != 0) {
            char* object = *(char**)(manager + 0x4c + (*(unsigned char*)(manager + 0x69) << 2));
            fn_800E3684(object, 2);
        }
    }

    if (arg == 1) {
        manager = g_IfMngr;
        if (*(unsigned int*)(manager + 0x54) != 0) {
            char* object = *(char**)(manager + 0x4c + (*(unsigned char*)(manager + 0x6a) << 2));
            fn_800E3684(object, 2);
        }
    }
}
}
