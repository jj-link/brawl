#include <em/em_area_module_impl.h>
#include <em/em_manager.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

class CameraVT {
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual Vec3f getMainPos();
};

extern "C" {
extern const float lbl_41_rodata_D58;
extern char __RTTI__5Enemy[];
extern char __RTTI__11StageObject[];
Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
void* fn_41_237A8(u32);
void fn_41_534C(Vec3f*, const Vec3f*);
u32 fn_41_D044(void*, u32);
void* getInstance__9emManagerFv();
void* getEnemyPtrFromId__9emManagerFi(void*, int);
Vec3f getPos__23soExternalValueAccesserFP11StageObject(void*);
Vec3f getHipPos__23ftExternalValueAccesserFP7Fighter(void*);
Vec3f getCenterPos__23emExternalValueAccesserFP5Enemy(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

Vec3f emAreaModuleImpl::getTargetPos(soModuleAccesser* acc, u32 target, bool center) {
    Vec3f result;
    float zero = lbl_41_rodata_D58;
    fn_41_5AC4(&result, zero, zero, zero);

    if (target <= 3) {
        void* obj = fn_41_237A8(target);
        if (obj == 0) return result;
        if (center == false) {
            Vec3f pos = getPos__23soExternalValueAccesserFP11StageObject(obj);
            fn_41_534C(&result, &pos);
            return result;
        }
        Vec3f hip = getHipPos__23ftExternalValueAccesserFP7Fighter(obj);
        fn_41_534C(&result, &hip);
        return result;
    }
    if (target - 4 <= 1) {
        void* enemy = __dynamic_cast(*(void**)((char*)acc + 8), 0x3c, __RTTI__5Enemy, __RTTI__11StageObject, 1);
        u32 taskId = *(u32*)((char*)enemy + 0xB0);
        if ((s32)target == 4) {
            if (center == false) {
                Vec3f pos = getPos__23soExternalValueAccesserFP11StageObject(enemy);
                fn_41_534C(&result, &pos);
            } else {
                Vec3f cen = getCenterPos__23emExternalValueAccesserFP5Enemy(enemy);
                fn_41_534C(&result, &cen);
            }
            return result;
        }
        if ((s32)target == 5) {
            u32 id = fn_41_D044(getInstance__9emManagerFv(), taskId);
            if (id == 0xffff) return result;
            void* e = getEnemyPtrFromId__9emManagerFi(getInstance__9emManagerFv(), id);
            if (e == 0) return result;
            if (center == false) {
                Vec3f pos = getPos__23soExternalValueAccesserFP11StageObject(e);
                fn_41_534C(&result, &pos);
            } else {
                Vec3f cen = getCenterPos__23emExternalValueAccesserFP5Enemy(e);
                fn_41_534C(&result, &cen);
            }
        }
    } else if ((s32)target == 6) {
        CameraVT* cam = *(CameraVT**)(*(char**)((char*)acc + 0xD8) + 0x60);
        Vec3f pos = cam->getMainPos();
        fn_41_534C(&result, &pos);
    }
    return result;
}
