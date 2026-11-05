#pragma force_active on

extern "C" {
void fn_8000D07C(void*, int);
void removeResAnmScn__11gfSceneRootFv(void*);
void fn_8000D7B8(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void* getBuffer__14gfFileIOHandleCFv(void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void* fn_2_3BC0(int, int);
void* getInstance__9itManagerFv(void*);
void __dt__20tyFigListDataManagerFv(void*, int);
void fn_800B8A0C(void*, int);
void exit__6gfTaskFv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14gfFileIOHandleFv(void*, int);
void fn_2_37C(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_2_data_720[];
extern void* g_gfSceneRoot;
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

class gfVCall2 : public gfPad5CProbe {
public:
    virtual void f(int);
};

extern "C" {

void* fn_2_2628(void* self, int arg1) {
    char* s = (char*)self;

    if (self != 0) {
        char* q;

        *(void**)(s + 0x3C) = lbl_2_data_720;

        {
            gfSlotNode* o = (gfSlotNode*)*(void**)((char*)g_gfSceneRoot + 0x450);
            while (o->count != 0) {
                if (o->count != 0) {
                    o->v12(o->count - 1);
                }
            }
        }

        {
            gfSlotNode* o = (gfSlotNode*)*(void**)((char*)g_gfSceneRoot + 0x3C0);
            while (o->count != 0) {
                if (o->count != 0) {
                    o->v12(o->count - 1);
                }
            }
        }

        {
            gfSlotNode* o = (gfSlotNode*)*(void**)((char*)g_gfSceneRoot + 0x390);
            while (o->count != 0) {
                if (o->count != 0) {
                    o->v12(o->count - 1);
                }
            }
        }

        fn_8000D07C(g_gfSceneRoot, 0);
        removeResAnmScn__11gfSceneRootFv(g_gfSceneRoot);
        fn_8000D7B8(g_gfSceneRoot);

        {
            char* p = s;
            unsigned int i = 0;
            do {
                void* obj = *(void**)(p + 0x5E4);
                if (obj != 0) {
                    Destroy__Q34nw4r3g3d6G3dObjFv(obj);
                    *(void**)(p + 0x5E4) = 0;
                }
                i++;
                p += 4;
            } while (i < 2);
        }

        {
            unsigned int i = 0;
            char* p = s;
            do {
                void* obj = *(void**)(p + 0x5B4);
                if (obj != 0) {
                    if (obj != 0) {
                        ((gfVCall2*)obj)->f(1);
                    }
                    *(void**)(p + 0x5B4) = 0;
                }
                i++;
                p += 4;
            } while (i < 0xC);
        }

        {
            unsigned int i = 0;
            q = s + 0x624;
            do {
                void* b = getBuffer__14gfFileIOHandleCFv(q);
                free__13gfHeapManagerFPv(b);
                release__14gfFileIOHandleFv(q);
                i++;
                q += 4;
            } while (i < 0xA);
        }

        {
            void* mgr = getInstance__9itManagerFv(fn_2_3BC0(*(int*)(s + 0x4C), 1));
            if (*(int*)((char*)mgr + 0x14B8) == 0) {
                __dt__20tyFigListDataManagerFv(*(void**)(s + 0x48), 1);
            }
        }
        fn_800B8A0C(*(void**)(s + 0x5F0), 1);
        fn_800B8A0C(*(void**)(s + 0x5F4), 1);
        fn_800B8A0C(*(void**)(s + 0x5F8), 1);
        exit__6gfTaskFv(*(void**)(s + 0x5EC));
        {
            void* t = *(void**)(s + 0x594);
            *(void**)(s + 0x5EC) = 0;
            if (t != 0) {
                exit__6gfTaskFv(t);
                *(void**)(s + 0x594) = 0;
            }
        }

        __destroy_arr(s + 0x624, __dt__14gfFileIOHandleFv, 4, 0xA);
        __destroy_arr(s + 0x54, fn_2_37C, 0xA8, 8);

        __dt__6gfTaskFv(s, 0);
        if (arg1 > 0) {
            __dl__FPv(s);
        }
    }

    return self;
}

}
