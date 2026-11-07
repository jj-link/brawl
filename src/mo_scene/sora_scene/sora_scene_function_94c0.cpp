#pragma force_active on
extern "C" int sprintf(char*, const char*, ...);
extern char* g_GameGlobal;
extern char lbl_1_data_38E8[];
extern char lbl_1_data_3950[];
extern const char* lbl_1_data_2428[];

extern "C" void* fn_1_94C0(char* self) {
    char* g;
    char* p;
    const char** names;
    int i;

    *(void**)(self + 0x0) = lbl_1_data_38E8;
    *(void**)(self + 0x4) = lbl_1_data_3950;
    *(int*)(self + 0xC) = 0;
    g = *(char**)(g_GameGlobal + 0x2C);
    g[0] = 4;
    g[1] = 2;
    g[2] = 0;
    g[3] = 3;
    g[4] = 0;
    g[5] = 0;
    g[6] = 0;
    names = lbl_1_data_2428;
    p = g + 8;
    i = 0;
    do {
        p[0] = 0;
        sprintf(p + 2, *names);
        p[0x17] = 0x78;
        names++;
        p[0x1A] = 0;
        p[0x1C] = 0;
        *(short*)(p + 0x1E) = 0;
        *(int*)(p + 0x20) = i;
        i++;
        p += 0x28;
    } while (i < 0x20);
    return self;
}
