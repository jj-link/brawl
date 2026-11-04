#pragma force_active on

extern "C" {

void fn_8005A9C0(void*);
void fn_8006526C(void*, int);
void nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(void*, bool);

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

struct MainObj {
    unsigned char pad0[0x34];
    void* f34;
    unsigned int f38;
    int f3C;
    void* f40;
    void* f44;
    void* f48;
    void* f4C;
    unsigned char pad50[8];
    unsigned char f58;
};

void fn_80062954(void* self, unsigned int arg1, unsigned int arg2) {
    MainObj* obj = (MainObj*)self;
    if (obj->f58 & 0x10) return;

    if (arg1 != 0 && obj->f34 != 0) {
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

    if (arg2 != 0 || obj->f3C < 0) {
        obj->f3C = 0;
    }

    obj->f58 = 8;

    if (arg1 == 1) {
        if (arg2 == 1) {
            if (obj->f44) {
                nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(obj->f44, false);
                if (obj->f4C) {
                    fn_8006526C(obj->f4C, 0);
                }
                if (obj->f40) {
                    IfaceF40* iface = (IfaceF40*)obj->f40;
                    iface->v13(obj->f44);
                    obj->f40 = 0;
                }
            }
            obj->f58 = (obj->f58 | 0x10) & ~0x20;
            return;
        }
    }
    if (arg1 == 0) {
        obj->f58 |= 0x20;
    }
}

}