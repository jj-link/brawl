#pragma force_active on
extern "C" {
void* getBuffer__14gfFileIOHandleCFv(void*);
void dumpAll__13gfHeapManagerFv();
void Init__Q34nw4r3g3d7ResFileFPv(void*);
void fn_8018E5D4(void*, void*);
int fn_8018E588(void*);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* GetResAnmScn__Q34nw4r3g3d7ResFileFi(void*, int);
void fn_801971D0(void*, void*);
void* fn_8019CA18(void*, void*, void*, int);
void fn_801AC650(void*, void*);
void* fn_801ACB68(void*);
void* getManager__15gfCameraManagerFv(void*);
void* fn_801AC554(void*, int);
void fn_80019718(void*, void*);
void fn_80018EC4(void*, void*);
void fn_801A7720(void*, void*);
void fn_80018778(void*);
void* getInstance__16CameraControllerFv();
void* getCameraController__16CameraControllerFQ216CameraController4Kind(void*, int);
void* __dynamic_cast(void*, int, void*, void*, int);
void fn_800A65E8();
void storeDefault__21cmMenuFixedControllerFv(void*);
extern char lbl_8059DEB0, __RTTI__18gfCameraController, __RTTI__21cmMenuFixedController;
}
struct O { char pad[0x44]; void* res; void* p48; void* p4C; };
extern "C" void fn_800B00B0(O* o, void* h) {
    float v[4]; char t[4]; void* s2; void* s3; void* a1; void* a2; void* a3; void* c; void* s1;
    o->res = getBuffer__14gfFileIOHandleCFv(h);
    if (o->res == 0) dumpAll__13gfHeapManagerFv();
    Init__Q34nw4r3g3d7ResFileFPv(&o->res);
    c = o->res;
    fn_8018E5D4(&o->res, &c);
    o->p4C = 0;
    if (fn_8018E588(&o->res)) {
        void* a = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2a);
        s2 = GetResAnmScn__Q34nw4r3g3d7ResFileFi(&o->res, 0);
        s1 = s2;
        fn_801971D0(&s2, &s1);
        s3 = s2;
        o->p4C = fn_8019CA18(a, t, &s3, 0);
        fn_801AC650(o->p48, o->p4C);
        char* m = (char*)getManager__15gfCameraManagerFv(fn_801ACB68(o->p48));
        a1 = fn_801AC554(o->p48, 0);
        fn_80019718(m, &a1);
        a2 = fn_801AC554(o->p48, 0);
        fn_80018EC4(m, &a2);
        a3 = fn_801AC554(o->p48, 0);
        fn_801A7720(&a3, v);
        *(float*)(m + 0xcc) = v[2];
        *(unsigned short*)(m + 0xfa) |= 0x80;
        *(unsigned short*)(m + 0xf8) = 0xe1;
        fn_80018778(m);
        __dynamic_cast(getCameraController__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 8), 4, &lbl_8059DEB0, &__RTTI__18gfCameraController, 0);
        fn_800A65E8();
        storeDefault__21cmMenuFixedControllerFv(__dynamic_cast(getCameraController__16CameraControllerFQ216CameraController4Kind(getInstance__16CameraControllerFv(), 9), 4, &__RTTI__21cmMenuFixedController, &__RTTI__18gfCameraController, 0));
    }
}
