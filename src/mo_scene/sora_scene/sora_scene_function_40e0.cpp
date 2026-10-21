#pragma force_active on

typedef unsigned char u8;

struct Sub {
    char pad[0x5D];
    u8 a : 2;
    u8 flag : 1;
    u8 b : 5;
};

struct LoaderManager {
    Sub* entries[7];
};

extern "C" LoaderManager* g_stLoaderManager;

extern "C" void fn_1_40E0(int arg0) {
    for (int i = 0; i < 7; ++i) {
        Sub* s = g_stLoaderManager->entries[i];
        if (s) {
            s->flag = arg0;
        }
    }
}
