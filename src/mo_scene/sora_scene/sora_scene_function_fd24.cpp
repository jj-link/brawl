#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void* getInstance__14gfSceneManagerFv();
void* fn_24_0();
void fn_24_3CC(void*, unsigned char);
void* fn_24_6E8();
void fn_24_8A0(void*);
void* fn_24_AC0();
void fn_24_D68(void*, unsigned char);
void* fn_24_1178();
void fn_24_12C4(void*);
void* fn_24_2EF8(void*);
void fn_800151FC(void*, const char*, int, int, int, int);
extern char lbl_1_data_4B08[];
}

struct Scene {
    char pad[8];
    void* archive;
    void* taskC;
    void* task10;
    void* task14;
    void* task18;
    void* task1C;
    unsigned char mode;
};

extern "C" void fn_1_FD24(Scene* self) {
    const char* data = lbl_1_data_4B08;
    void* p = __nw__FUlQ25Heaps8HeapType(0x80, 0x2A);
    if (p)
        p = __ct__9gfArchiveFv(p);
    self->archive = p;

    if (*(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == 0 ||
        *(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == -1) {
        self->taskC = fn_24_0();
        fn_24_3CC(self->taskC, self->mode);
    }

    if (*(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == 1 ||
        *(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == -2) {
        self->task10 = fn_24_6E8();
        fn_24_8A0(self->task10);
    }

    if (*(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == 0 ||
        *(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == -1) {
        self->task14 = fn_24_AC0();
        fn_24_D68(self->task14, self->mode);
    }

    if (*(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == 0 ||
        *(int*)((char*)getInstance__14gfSceneManagerFv() + 0x280) == -1) {
        self->task18 = fn_24_1178();
        fn_24_12C4(self->task18);
    }

    p = __nw__FUlQ25Heaps8HeapType(0x204, 0x2A);
    if (p)
        p = fn_24_2EF8(p);
    self->task1C = p;

    if (self->taskC) {
        switch (self->mode) {
        case 0:
            fn_800151FC(self->archive, data + 0x78, 0x2B, 0, 0, 0xFF);
            break;
        case 2:
        default:
            fn_800151FC(self->archive, data + 0x90, 0x2B, 0, 0, 0xFF);
            break;
        case 3:
            fn_800151FC(self->archive, data + 0xA8, 0x2B, 0, 0, 0xFF);
            break;
        case 4:
            fn_800151FC(self->archive, data + 0xC0, 0x2B, 0, 0, 0xFF);
            break;
        }
    } else {
        fn_800151FC(self->archive, data + 0xD8, 0x2B, 0, 0, 0xFF);
    }
}
