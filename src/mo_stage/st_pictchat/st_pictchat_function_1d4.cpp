#pragma force_active on
class Class_BA8 {
public:
    virtual void fn_73_2BB0(int);
};

extern "C" {
extern char lbl_73_data_888[];
void __dla__FPv(void* p);
void __dl__FPv(void* p);
void releaseArchive__15stCommonGimmickFv(void* self);
void __dt__7stMeleeFv(void* self, int flag);

void* fn_73_1D4(void* self, int arg1) {
    if (self != 0) {
        void* p;
        *(char**)((char*)self + 0x3C) = lbl_73_data_888;
        p = *(void**)((char*)self + 0x3D0);
        if (p != 0) {
            __dla__FPv(p);
        }
        p = *(void**)((char*)self + 0x3F0);
        if (p != 0) {
            if (p != 0) {
                __dla__FPv((char*)p - 0x10);
            }
        }
        p = *(void**)((char*)self + 0x42C);
        if (p != 0) {
            __dl__FPv(p);
        }
        for (unsigned char i = 0; i < 0x1B; i++) {
            Class_BA8* obj = *(Class_BA8**)((char*)self + (i << 2) + 0x208);
            if (obj != 0) {
                obj->fn_73_2BB0(1);
            }
            *(void**)((char*)self + (i << 2) + 0x208) = 0;
        }
        releaseArchive__15stCommonGimmickFv(self);
        __dt__7stMeleeFv(self, 0);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
