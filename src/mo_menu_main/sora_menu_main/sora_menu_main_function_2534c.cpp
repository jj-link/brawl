#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
int isCharUsable__6muMenuFiii(int);
void* fn_8004E5D8(void*, void*);
}

extern "C" int fn_2_2534C(void* arg) {
    int sum = 0;
    for (int i = 0; i < 0x23; i++) {
        if (isCharUsable__6muMenuFiii(i)) {
            sum += static_cast<unsigned short*>(fn_8004E5D8(g_GameGlobal, arg))[i];
        }
    }
    return sum;
}
