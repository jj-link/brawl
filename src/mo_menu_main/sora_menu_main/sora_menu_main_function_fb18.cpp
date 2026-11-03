#pragma force_active on

extern "C" {
void fn_800AEC70(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void* getBuffer__14gfFileIOHandleCFv(void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void fn_800B8A0C(void*, int);
void fn_800AD87C(void*, int);
void exit__6gfTaskFv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_2_data_18E8[];
extern void* lbl_2_bss_40;
}

class gfPad5CProbe {
public:
    char pad[0x5C];
};

class gfVCallProbe : public gfPad5CProbe {
public:
    virtual void f(int);
};

extern "C" {

void* fn_2_FB18(void* self, int arg1) {
    char* s = (char*)self;

    if (self != 0) {
        unsigned int i;
        char* p;
        char* q;

        *(void**)(s + 0x3C) = lbl_2_data_18E8;
        fn_800AEC70(*(void**)(s + 0x4C));

        p = s;
        i = 0;
        do {
            void* o = *(void**)(p + 0x52BC);
            if (o != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(o);
                *(void**)(p + 0x52BC) = 0;
            }
            i++;
            p += 4;
        } while (i < 2);

        p = s;
        i = 0;
        do {
            void* o = *(void**)(p + 0x5168);
            if (o != 0) {
                if (o != 0) {
                    ((gfVCallProbe*)o)->f(1);
                }
                *(void**)(p + 0x5168) = 0;
            }
            i++;
            p += 4;
        } while (i < 0x55);

        q = s + 0x5364;
        i = 0;
        do {
            void* b = getBuffer__14gfFileIOHandleCFv(q);
            free__13gfHeapManagerFPv(b);
            release__14gfFileIOHandleFv(q);
            i++;
            q += 4;
        } while (i < 4);

        p = s;
        i = 0;
        do {
            void* o = *(void**)(p + 0x52D8);
            if (o != 0) {
                free__13gfHeapManagerFPv(o);
                *(void**)(p + 0x52D8) = 0;
            }
            i++;
            p += 4;
        } while (i < 0x20);

        if (lbl_2_bss_40 != 0) {
            free__13gfHeapManagerFPv(lbl_2_bss_40);
            lbl_2_bss_40 = 0;
        }

        fn_800B8A0C(*(void**)(s + 0x52C8), 1);
        fn_800B8A0C(*(void**)(s + 0x52D0), 1);
        fn_800AD87C(*(void**)(s + 0x4C), 1);
        exit__6gfTaskFv(*(void**)(s + 0x52C4));
        *(void**)(s + 0x52C4) = 0;
        exit__6gfTaskFv(*(void**)(s + 0x40));
        *(void**)(s + 0x40) = 0;

        __destroy_arr(s + 0x5394, __dt__14gfFileIOHandleFv, 4, 0x20);
        __destroy_arr(s + 0x5364, __dt__14gfFileIOHandleFv, 4, 4);

        __dt__6gfTaskFv(s, 0);
        if (arg1 > 0) {
            __dl__FPv(s);
        }
    }

    return self;
}

}
