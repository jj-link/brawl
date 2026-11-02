#pragma force_active on

struct LObj {
    char pad[0x5D];
    unsigned char flags;
};
struct LMgr {
    LObj* o[4];
};

extern "C" {
void* getInstance__14gfSceneManagerFv();
void setNextScene__14gfSceneManagerFv(void* mgr, const char* name, int arg);
void setNextSequence__14gfSceneManagerFv(void* mgr, const char* name, int arg);
void fn_1_2268C(void*);
void fn_8005033C(void*);
extern const char lbl_1_data_6D60[];
extern LMgr* g_stLoaderManager;
extern void** g_GameGlobal;
extern char* g_gfApplication;

#define SETF(i) do { LObj* p = g_stLoaderManager->o[i]; if (p != 0) p->flags |= 0x20; } while (0)
#define CLRF(i) do { LObj* p = g_stLoaderManager->o[i]; if (p != 0) p->flags &= ~0x20; } while (0)
#define SETALL() do { SETF(0); SETF(1); SETF(2); SETF(3); } while (0)
#define CLRALL() do { CLRF(0); CLRF(1); CLRF(2); CLRF(3); } while (0)

void fn_1_221D0(char* self) {
    const char* str = lbl_1_data_6D60;
    char* mgr = (char*)getInstance__14gfSceneManagerFv();
    int cont = 1;
    while (cont) {
        cont = 0;
        switch (*(unsigned int*)(self + 8)) {
        default:
            *(int*)(self + 8) = 2;
            *(int*)(self + 0x14) = 1;
        case 0:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x10, *(unsigned char*)(self + 0x10));
            *(int*)(self + 8) = 1;
            break;
        case 1:
            cont = 1;
            *(int*)(self + 8) = *(int*)(self + 0xC);
            break;
        case 2:
            *(int*)(self + 8) = 0;
            cont = 1;
            *(int*)(self + 0xC) = 3;
            *(unsigned char*)(self + 0x10) = 0xD;
            break;
        case 3:
            fn_1_2268C(self);
            SETALL();
            setNextScene__14gfSceneManagerFv(mgr, str + 0x20, *(int*)(self + 0x14));
            *(int*)(self + 8) = 4;
            break;
        case 4:
            switch (*(int*)(mgr + 0x284)) {
            case 0:
                *(int*)(self + 0xC) = 0xC;
                *(unsigned char*)(self + 0x10) = 2;
                fn_8005033C(g_GameGlobal[2]);
                break;
            case 1:
                switch (*(int*)(self + 0x18)) {
                case 0:
                    *(int*)(self + 0xC) = 5;
                    *(int*)(self + 0x18) = *(int*)(self + 0x18) + 1;
                    break;
                case 1:
                    *(int*)(self + 0xC) = 7;
                    *(int*)(self + 0x18) = 0;
                    break;
                }
                *(unsigned char*)(self + 0x10) = 0xD;
                break;
            }
            *(int*)(self + 8) = 0;
            cont = 1;
            CLRALL();
            break;
        case 5:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x28, 1);
            *(int*)(self + 8) = 6;
            break;
        case 6:
            switch (*(int*)(mgr + 0x284)) {
            default:
                *(int*)(self + 8) = 9;
                break;
            case 0:
                *(int*)(self + 8) = 0xC;
                break;
            case 1:
                *(int*)(self + 8) = 2;
                *(int*)(self + 0x14) = 1;
                break;
            }
            cont = 1;
            break;
        case 7:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x30, 0);
            *(int*)(self + 8) = 8;
            break;
        case 8:
            switch (*(int*)(mgr + 0x284)) {
            default:
                *(int*)(self + 8) = 9;
                break;
            case 0:
                *(int*)(self + 8) = 0xC;
                break;
            case 1:
                *(int*)(self + 8) = 2;
                *(int*)(self + 0x14) = 1;
                break;
            }
            cont = 1;
            break;
        case 9:
            *(int*)(self + 8) = 0;
            *(int*)(self + 0xC) = 0xA;
            *(unsigned char*)(self + 0x10) = 0;
            CLRALL();
            cont = 1;
            break;
        case 10:
            setNextScene__14gfSceneManagerFv(mgr, str + 0x40, 0);
            *(int*)(self + 8) = 0xB;
            break;
        case 11:
            switch (*(int*)(mgr + 0x284)) {
            case 2:
                break;
            case 3:
                *(int*)(self + 8) = 0xC;
                break;
            case 1:
                *(int*)(self + 8) = 2;
                *(int*)(self + 0x14) = 1;
                break;
            case 0:
                switch (*(int*)(self + 0x18)) {
                case 1:
                    *(int*)(self + 8) = 2;
                    *(int*)(self + 0x14) = 1;
                    break;
                default:
                    *(int*)(self + 8) = 2;
                    *(int*)(self + 0x14) = 0;
                    break;
                }
                break;
            }
            cont = 1;
            break;
        case 12:
            fn_8005033C(g_GameGlobal[2]);
            CLRALL();
            g_gfApplication[0x110] = *(unsigned char*)(self + 0x1C);
            setNextSequence__14gfSceneManagerFv(mgr, str + 0x48, 0);
            *(int*)(self + 8) = 0xD;
            break;
        }
    }
}
}
