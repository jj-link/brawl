#pragma force_active on
extern "C" void* fn_61_2320(void* self, const char* name);
extern "C" void* memset(void* p, int c, unsigned long n);
extern "C" char lbl_61_data_1494[];
extern "C" char* g_GameGlobal;
extern const float lbl_61_rodata_50;
extern const float lbl_61_rodata_54;

extern "C" void* fn_61_3B2C(void* self, const char* name) {
    char* obj = (char*)self;
    fn_61_2320(self, name);
    *(char*)(obj + 0x158) = 0;
    *(void**)(obj + 0x3c) = lbl_61_data_1494;
    *(char*)(obj + 0x159) = 0;
    *(int*)(obj + 0x15c) = 0;
    *(int*)(obj + 0x160) = 0;
    *(int*)(obj + 0x164) = 0;
    *(int*)(obj + 0x168) = 0;
    *(char*)(obj + 0x16c) = 1;
    *(char*)(obj + 0x16d) = 1;
    *(int*)(obj + 0x170) = 0;
    memset(obj + 0x174, 0, 8);
    memset(obj + 0x17c, 0, 0x1c);
    memset(obj + 0x198, 0, 0x2c);
    memset(obj + 0x1c4, 0, 4);
    memset(obj + 0x1c8, 0, 4);
    memset(obj + 0x1cc, 0, 8);
    *(int*)(obj + 0x1d4) = 0;
    *(int*)(obj + 0x1d8) = 0;
    *(int*)(obj + 0x1dc) = 0;
    *(int*)(obj + 0x1e0) = 0;
    *(int*)(obj + 0x1e4) = 0;
    *(int*)(obj + 0x1e8) = 0;
    *(int*)(obj + 0x1ec) = 0;
    *(float*)(obj + 0x1f0) = lbl_61_rodata_50;
    *(char*)(obj + 0x1f4) = 7;
    *(float*)(obj + 0x1f8) = lbl_61_rodata_54;
    *(float*)(obj + 0x1fc) = lbl_61_rodata_54;
    *(char*)(obj + 0x200) = 0;
    *(int*)(obj + 0x204) = -1;
    *(char*)(obj + 0x208) = 0;
    unsigned char* g = *(unsigned char**)((char*)g_GameGlobal + 8);
    if (g == 0) {
        return self;
    }
    unsigned int v = ((unsigned int)g[8] >> 2) & 0x3F;
    if (v != 7) {
        return self;
    }
    if (g[0x10] == 0x1F) {
        *(char*)(obj + 0x208) = 1;
    }
    return self;
}
