#pragma force_active on
extern "C" {
extern char lbl_59_data_0[];
extern unsigned char lbl_59_data_2E8[];
extern const float lbl_59_rodata_0;
extern const float lbl_59_rodata_4;

void __ct__7stMeleeFPCcQ26Stages11srStageKind(void*, const char*, int);
void __ct__13grTenganEventFv(void*);
int randi__Fl(long);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

void* fn_59_A4(void* self) {
    unsigned char* p = (unsigned char*)self;

    __ct__7stMeleeFPCcQ26Stages11srStageKind(p, lbl_59_data_0, 20);
    *(void**)(p + 0x3c) = lbl_59_data_2E8;

    __ct__13grTenganEventFv(p + 0x1dc);
    __ct__13grTenganEventFv(p + 0x288);
    __ct__13grTenganEventFv(p + 0x334);
    __ct__13grTenganEventFv(p + 0x3e0);
    __ct__13grTenganEventFv(p + 0x48c);
    __ct__13grTenganEventFv(p + 0x538);
    __ct__13grTenganEventFv(p + 0x5e4);
    __ct__13grTenganEventFv(p + 0x6e8);

    *(int*)(p + 0x6bc) = -1;
    *(int*)(p + 0x6c0) = -1;
    *(int*)(p + 0x6c4) = 0;
    p[0x6c8] = 0;
    p[0x6c9] = 1;
    p[0x6ca] = 2;
    p[0x6cb] = 3;

    unsigned int a;
    unsigned int b;
    int i = 0;
    do {
        a = randi__Fl(4);
        if (a >= 3) {
            a = 3;
        }
        b = randi__Fl(4);
        if (b >= 3) {
            b = 3;
        }
        unsigned char t;
        unsigned char* pa;
        unsigned char* pb;
        pb = p + b;
        pa = p + a;
        t = pa[0x6c8];
        pa[0x6c8] = pb[0x6c8];
        pb[0x6c8] = t;
        i++;
    } while (i < 32);

    p[0x1d8] = 0;
    *(float*)(p + 0x6b0) = lbl_59_rodata_0;
    *(int*)(p + 0x6b4) = -1;
    p[0x6b8] = 0;
    *(int*)(p + 0x6ac) = 0;
    *(float*)(p + 0x794) = lbl_59_rodata_4;
    p[0x6e5] = 0;
    p[0x6e6] = 0;
    p[0x6e7] = 0xff;
    *(float*)(p + 0x798) = lbl_59_rodata_4;
    *(float*)(p + 0x79c) = lbl_59_rodata_0;
    *(float*)(p + 0x7a0) = lbl_59_rodata_0;
    *(float*)(p + 0x7a4) = lbl_59_rodata_0;
    *(float*)(p + 0x7a8) = lbl_59_rodata_0;
    *(float*)(p + 0x7ac) = lbl_59_rodata_0;
    *(float*)(p + 0x7b0) = lbl_59_rodata_0;
    *(float*)(p + 0x7b4) = lbl_59_rodata_0;
    *(float*)(p + 0x7b8) = lbl_59_rodata_0;
    *(float*)(p + 0x7bc) = lbl_59_rodata_4;
    *(float*)(p + 0x7c0) = lbl_59_rodata_4;
    *(float*)(p + 0x6cc) = lbl_59_rodata_0;
    *(float*)(p + 0x6d0) = lbl_59_rodata_0;
    *(float*)(p + 0x6d4) = lbl_59_rodata_0;
    *(float*)(p + 0x6d8) = lbl_59_rodata_4;
    *(float*)(p + 0x6dc) = lbl_59_rodata_4;
    *(float*)(p + 0x6e0) = lbl_59_rodata_4;
    p[0x6a0] = 0;
    *(float*)(p + 0x6a4) = lbl_59_rodata_0;
    p[0x6a8] = 0;

    *(void**)(p + 0x690) = __nw__FUlQ25Heaps8HeapType(0x40, 0xf);
    *(void**)(p + 0x694) = __nw__FUlQ25Heaps8HeapType(0x40, 0xf);
    return self;
}
}
