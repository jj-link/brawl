#pragma force_active on
extern "C" {
extern char* g_IfAdvMngr;
extern char* g_IfMngr;
extern float lbl_40_rodata_228;

void fn_801078B8(char*);
void fn_800DCF18(char*, int);
void fn_800E3684(char*, int);

void fn_40_15A44(int unused, int arg, int flag)
{
    if (g_IfAdvMngr != 0) {
        fn_801078B8(g_IfAdvMngr);
    }

    char* manager = g_IfMngr;
    if (manager == 0) {
        return;
    }

    if (flag == 0) {
        fn_800DCF18(manager, arg);
        return;
    }

    if (arg == 0) {
        if (*(unsigned int*)(manager + 0x50) != 0) {
            char* object = *(char**)(manager + 0x4c + (*(unsigned char*)(manager + 0x69) << 2));
            if (*(unsigned int*)(object + 0x1c) == *(unsigned int*)(object + 0x18)) {
                *(float*)(object + 0x264) = lbl_40_rodata_228;
                fn_800E3684(object, 1);
            }
        }
    }

    if (arg == 1) {
        manager = g_IfMngr;
        if (*(unsigned int*)(manager + 0x54) != 0) {
            char* object = *(char**)(manager + 0x4c + (*(unsigned char*)(manager + 0x6a) << 2));
            if (*(unsigned int*)(object + 0x1c) == *(unsigned int*)(object + 0x18)) {
                *(float*)(object + 0x264) = lbl_40_rodata_228;
                fn_800E3684(object, 1);
            }
        }
    }
}
}
