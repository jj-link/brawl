#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct Manager {
    u32 values[14];
    u32 field38;
    u32 field3c;
    u32* field40;
    u32* field44;
    u8 field48;
    u8 field49;
    u8 pad[2];
    u32 field4c;
    u32 field50;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern Manager* g_stLoaderManager;
extern u32 lbl_27_data_4CCC0;

void fn_27_23A410() {
    if (g_stLoaderManager == 0) {
        Manager* p = (Manager*)__nw__FUlQ25Heaps8HeapType(0x54, 2);
        if (p) {
            p->field38 = 0;
            p->field3c = 0;
            p->field48 = 0;
            p->field49 = 0;
            p->field4c = lbl_27_data_4CCC0;
            p->field50 = 0;

            u32* a = (u32*)__nw__FUlQ25Heaps8HeapType(4, 2);
            if (a) *a = 0;
            p->field40 = a;

            u32* b = (u32*)__nw__FUlQ25Heaps8HeapType(4, 2);
            if (b) *b = 0;
            p->field44 = b;

            p->values[0] = 0;
            p->values[1] = 0;
            p->values[2] = 0;
            p->values[3] = 0;
            p->values[4] = 0;
            p->values[5] = 0;
            p->values[6] = 0;
            p->values[7] = 0;
            p->values[8] = 0;
            p->values[9] = 0;
            p->values[10] = 0;
            p->values[11] = 0;
            p->values[12] = 0;
            p->values[13] = 0;
        }
        g_stLoaderManager = p;
    }
}
}
