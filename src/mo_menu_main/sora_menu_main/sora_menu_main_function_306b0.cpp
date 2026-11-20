#pragma force_active on

extern "C" {
void fn_1_7EC4(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void free__13gfHeapManagerFPv(void*);
void fn_800B8A0C(void*, int);
void fn_2_647C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_2_data_4188[];
}

class gfSlotNode {
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
    virtual void v12(int);
    char pad[0xE0];
    int count;
};

class gfPad5CProbe {
public:
    char pad[0x5C];
};

class gfVCallProbe : public gfPad5CProbe {
public:
    virtual void f(int);
};

extern "C" {

void* fn_2_306B0(void* self, int arg1) {
    char* s = (char*)self;

    if (self != 0) {
        gfSlotNode* o;
        void* h = *(void**)(s + 0x40);
        int off;
        int i;

        *(void**)(s + 0x3C) = lbl_2_data_4188;
        if (h != 0) {
            fn_1_7EC4(*(void**)h);
            i = 0;
            off = 0;
            do {
                o = (gfSlotNode*)*(void**)(*(char**)(s + 0x40) + off + 0x9C);
                if (o != 0) {
                    while (o->count != 0) {
                        if (o->count != 0) {
                            o->v12(o->count - 1);
                        }
                    }
                    Destroy__Q34nw4r3g3d6G3dObjFv(*(void**)(*(char**)(s + 0x40) + off + 0x9C));
                }
                i++;
                off += 4;
            } while (i < 5);

            off = 0;
            i = 0;
            do {
                void* o2 = *(void**)(*(char**)(s + 0x40) + i + 0x10);
                if (o2 != 0) {
                    ((gfVCallProbe*)o2)->f(1);
                }
                off++;
                i += 4;
            } while (off < 0x23);

            if (*(void**)(*(char**)(s + 0x40) + 0x4) != 0) {
                free__13gfHeapManagerFPv(*(void**)(*(char**)(s + 0x40) + 0x4));
            }
            if (*(void**)(*(char**)(s + 0x40) + 0x8) != 0) {
                free__13gfHeapManagerFPv(*(void**)(*(char**)(s + 0x40) + 0x8));
            }
            if (*(void**)(*(char**)(s + 0x40) + 0x164) != 0) {
                fn_800B8A0C(*(void**)(*(char**)(s + 0x40) + 0x164), 1);
            }
            if (*(void**)(*(char**)(s + 0x40) + 0xC) != 0) {
                free__13gfHeapManagerFPv(*(void**)(*(char**)(s + 0x40) + 0xC));
            }
            free__13gfHeapManagerFPv(*(void**)(s + 0x40));
            {
                i = (int)(s + 0x44);
                *(void**)(s + 0x40) = 0;
                off = 0;
                do {
                    cancelRequest__14gfFileIOHandleFv((void*)i);
                    off++;
                    i += 4;
                } while (off < 3);
            }
        }

        __destroy_arr(s + 0x44, fn_2_647C, 4, 3);
        __dt__6gfTaskFv(s, 0);
        if (arg1 > 0) {
            __dl__FPv(s);
        }
    }

    return self;
}

}
