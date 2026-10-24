#pragma force_active on

typedef unsigned char u8;

class MenuObject {
    u8 padding[0x5C];

public:
    virtual ~MenuObject();
};

extern "C" {
extern u8 lbl_80456D54[];

void fn_800B8A0C(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void free__13gfHeapManagerFPv(void*);
}

extern "C" void* fn_800BF2CC(u8* obj, int deleting) {
    if (obj) {
        void* heap = *(void**)(obj + 0x118);
        *(void**)(obj + 0x3C) = lbl_80456D54;
        if (heap) {
            free__13gfHeapManagerFPv(heap);
        }

        if (*(void**)(obj + 0x48)) {
            fn_800B8A0C(*(void**)(obj + 0x48), 1);
        }

        MenuObject* p = *(MenuObject**)(obj + 0x40);
        if (p) {
            delete p;
        }

        __dt__6gfTaskFv(obj, 0);
        if (deleting > 0) {
            __dl__FPv(obj);
        }
    }

    return obj;
}
