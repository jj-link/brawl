#pragma force_active on
typedef unsigned char u8;

class LoopObj {
    u8 pad[0x5C];
public:
    virtual void fn(int);
};

class Obj150 {
    u8 pad[0x3C];
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
};

extern "C" {
extern u8 lbl_6_data_8F0[];
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
void fn_80154420(void*, int);
void fn_800B8A0C(void*, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8014C960(void);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_6_A58C(void* self, int deleting)
{
    if (self) {
        u8* obj = (u8*)self;

        void* prev = *reinterpret_cast<void**>(obj + 0x140);
        *reinterpret_cast<void**>(obj + 0x3C) = (void*)lbl_6_data_8F0;
        if (prev) {
            exit__6gfTaskFv(prev);
        }

        void* heap = *reinterpret_cast<void**>(obj + 0x14C);
        if (heap) {
            free__13gfHeapManagerFPv(heap);
        }

        void* a = *reinterpret_cast<void**>(obj + 0x130);
        if (a) {
            fn_80154420(a, 1);
        }

        void* b = *reinterpret_cast<void**>(obj + 0x78);
        if (b) {
            fn_800B8A0C(b, 1);
        }

        void* c = *reinterpret_cast<void**>(obj + 0x70);
        if (c) {
            Destroy__Q34nw4r3g3d6G3dObjFv(c);
        }

        u8* cursor = obj;
        for (int i = 0; i < 0xC; ++i, cursor += 4) {
            LoopObj* entry = *reinterpret_cast<LoopObj**>(cursor + 0x40);
            if (entry && entry) {
                entry->fn(1);
            }
        }

        Obj150* d = *reinterpret_cast<Obj150**>(obj + 0x150);
        if (d) {
            d->v23();
        }

        fn_8014C960();
        __dt__6gfTaskFv(self, 0);

        if (deleting > 0) {
            __dl__FPv(self);
        }
    }

    return self;
}
}