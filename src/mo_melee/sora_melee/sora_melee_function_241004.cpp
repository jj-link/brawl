#pragma force_active on

typedef unsigned char u8;

extern "C" {
extern void* g_IfWifiprMngr;
void fn_800FC43C(void*, int);
int fn_800FC660(void*);
void fn_800FC840(void*);
}

extern "C" void fn_27_241004(u8* self) {
    if (self[0x46] != 0) {
        switch ((int)self[0x44]) {
        case 0:
            self[0x44] = 1;
            break;
        case 1:
            fn_800FC43C(g_IfWifiprMngr, 1);
            self[0x44] = 2;
            break;
        case 2:
            if (fn_800FC660(g_IfWifiprMngr) != 0)
                self[0x44] = 3;
            break;
        case 3:
            if (self[0x47] == 1)
                self[0x44] = 5;
            break;
        case 5:
            if (self[0x47] == 1)
                self[0x44] = 6;
            else
                self[0x44] = 0;
            fn_800FC840(g_IfWifiprMngr);
            break;
        }
    }
}
