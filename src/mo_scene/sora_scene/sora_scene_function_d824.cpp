#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* __ct__9gfArchiveFv(void*);
void* getInstance__16CameraControllerFv();
void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
void fn_1_3C68(void*, int, void*, void*, int);
int fn_1_DB54(void*, int);
void* memset(void*, int, unsigned long);
extern unsigned char lbl_1_data_4430[];
}

inline void* operator new(unsigned long n, int heap) {
    return __nw__FUlQ25Heaps8HeapType(n, heap);
}

struct Loader {
    int a, b, c, d, e, f, g;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char rest : 5;
    unsigned char padding[3];

    Loader() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
        e = 0;
        bit0 = 0;
        g = 0;
        bit1 = 1;
        f = 255;
        bit2 = 0;
    }
};

extern "C" void fn_1_D824(char* self) {
    if (*(int*)(self + 0x444) == 0) {
        void* arc = __nw__FUlQ25Heaps8HeapType(0x80, 0x2b);
        if (arc)
            arc = __ct__9gfArchiveFv(arc);
        *(void**)(self + 0x450) = arc;

        Loader* loader = new (0x2b) Loader;
        *(Loader**)(self + 0x454) = loader;

        *(void**)(self + 0x368) = getInstance__16CameraControllerFv();
        fn_1_3C68(
            *(void**)(self + 0x454),
            0x2b,
            lbl_1_data_4430,
            *(void**)(self + 0x450),
            0x100000
        );
        changeInput__16CameraControllerFQ216CameraController4Kind(
            *(void**)(self + 0x368), 8
        );
        *(int*)(self + 0x3ac) = 0;
    } else {
        *(int*)(self + 0x3ac) = fn_1_DB54(self, 0);
    }
    memset(self + 0x449, 0, 4);
}
