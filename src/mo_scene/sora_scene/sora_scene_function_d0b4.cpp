#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void loadMenuSound__6muMenuFv();
void fn_1_3C68(void*, int, void*, void*, int);
extern char lbl_1_data_432C[];
extern char lbl_1_data_4348[];
void* memset(void*, int, unsigned long);
}

struct Loader {
    unsigned int a, b, c, d, e, f, g;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
};

inline Loader* makeLoader(int heap) {
    Loader* p = (Loader*)__nw__FUlQ25Heaps8HeapType(32, heap);
    if (p) {
        p->a = 0;
        p->b = 0;
        p->c = 0;
        p->d = 0;
        p->e = 0;
        p->bit0 = 0;
        p->g = 0;
        p->bit1 = 1;
        p->f = 255;
        p->bit2 = 0;
    }
    return p;
}

extern "C" void fn_1_D0B4(char* self) {
    self[0x408] = 0;

    void* p = __nw__FUlQ25Heaps8HeapType(128, 43);
    if (p)
        p = __ct__9gfArchiveFv(p);
    *(void**)(self + 0x410) = p;

    p = __nw__FUlQ25Heaps8HeapType(128, 43);
    if (p)
        p = __ct__9gfArchiveFv(p);
    *(void**)(self + 0x3b0) = p;

    p = __nw__FUlQ25Heaps8HeapType(128, 41);
    if (p)
        p = __ct__9gfArchiveFv(p);
    *(void**)(self + 0x3ac) = p;

    *(Loader**)(self + 0x414) = makeLoader(43);
    *(Loader**)(self + 0x418) = makeLoader(41);
    *(void**)(self + 0x360) = getInstance__16CameraControllerFv();

    fn_1_3C68(
        *(void**)(self + 0x414), 43, lbl_1_data_432C,
        *(void**)(self + 0x410), 0x100000);
    fn_1_3C68(
        *(void**)(self + 0x418), 41, lbl_1_data_4348, 0, 0);

    changeInput__16CameraControllerFQ216CameraController4Kind(
        *(void**)(self + 0x360), 8);
    loadMenuSound__6muMenuFv();
    *(int*)(self + 0x400) = 0;
    memset(self + 0x409, 0, 4);
}
