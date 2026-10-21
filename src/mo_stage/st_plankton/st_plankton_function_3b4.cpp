#pragma force_active on
extern "C" {
extern unsigned char lbl_74_data_2A8[];
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void releaseArchive__15stCommonGimmickFv(void*);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
}

class GF {
public:
    virtual void fn(int);
};

extern "C" void* fn_74_3B4(void* obj, int arg1) {
    if (obj) {
        void* p = *(void**)((unsigned char*)obj + 0x1D8);
        *(void**)((unsigned char*)obj + 0x3C) = lbl_74_data_2A8;
        if (p) {
            Destroy__Q34nw4r3g3d6G3dObjFv(p);
        }
        GF* q = *(GF**)((unsigned char*)obj + 0xE94);
        *(void**)((unsigned char*)obj + 0x1D8) = 0;
        if (q) {
            if (q) {
                q->fn(1);
            }
        }
        *(void**)((unsigned char*)obj + 0xE94) = 0;
        releaseArchive__15stCommonGimmickFv(obj);
        __dt__7stMeleeFv(obj, 0);
        if (arg1 > 0) {
            __dl__FPv(obj);
        }
    }
    return obj;
}
