#pragma force_active on

extern "C" {

void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*);
void fn_8005A9C0(void*);
void __dla__FPv(void*);

struct MainObj {
    unsigned char pad0[0x34];
    void* f34;
    unsigned int f38;
    unsigned char pad3C[4];
    void* f40;
    void* f44;
    void* f48;
    void* f4C;
};

struct F48Obj {
    void* f0;
    unsigned char f4;
    unsigned char pad5[3];
    void* f8;
    void* fC;
    void* f10;
    void* f14;
    void* f18;
    void* f1C;
};

class IfaceF4C {
public:
    virtual void v0(int) = 0;
};

class IfaceF40 {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void v13(void*) = 0;
};

void fn_80062734(void* arg0, unsigned int arg1) {
    MainObj* obj = (MainObj*)arg0;
    if (obj->f44) {
        IfaceF40* f40 = (IfaceF40*)obj->f40;
        if (f40) {
            f40->v13(obj->f44);
            obj->f40 = 0;
        }
        IfaceF4C* f4C = (IfaceF4C*)obj->f4C;
        if (f4C) {
            if (f4C) {
                if (f4C) {
                    f4C->v0(1);
                }
                obj->f4C = 0;
            }
        }
        if (obj->f48) {
            unbind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(obj->f44);
            F48Obj* heap = (F48Obj*)obj->f48;
            if (heap->fC) {
                Destroy__Q34nw4r3g3d6G3dObjFv(heap->fC);
            }
            if (heap->f8) {
                Destroy__Q34nw4r3g3d6G3dObjFv(heap->f8);
            }
            if (heap->f10) {
                Destroy__Q34nw4r3g3d6G3dObjFv(heap->f10);
            }
            if (heap->f14) {
                Destroy__Q34nw4r3g3d6G3dObjFv(heap->f14);
            }
            if (heap->f18) {
                Destroy__Q34nw4r3g3d6G3dObjFv(heap->f18);
            }
            if (heap->f1C) {
                Destroy__Q34nw4r3g3d6G3dObjFv(heap->f1C);
            }
            if (heap->f0 && heap->f4) {
                free__13gfHeapManagerFPv(heap->f0);
                heap->f0 = 0;
            }
            heap->fC = 0;
            heap->f8 = 0;
            heap->f10 = 0;
            heap->f14 = 0;
            heap->f18 = 0;
            heap->f1C = 0;
            free__13gfHeapManagerFPv(obj->f48);
            obj->f48 = 0;
        }
        Destroy__Q34nw4r3g3d6G3dObjFv(obj->f44);
        obj->f44 = 0;
    }
    if (arg1 == 1) {
        if (obj->f34) {
            unsigned int offset;
            unsigned int i;
            void* ptr;
            i = 0;
            offset = 0;
            ptr = 0;
            while (i < obj->f38) {
                ptr = *(void**)((char*)obj->f34 + offset);
                if (ptr) {
                    fn_8005A9C0(ptr);
                    *(void**)((char*)obj->f34 + offset) = 0;
                }
                offset += 4;
                i++;
            }
        }
    }
    if (obj->f34) {
        __dla__FPv(obj->f34);
        obj->f34 = 0;
    }
}

}
