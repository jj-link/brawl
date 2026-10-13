#include <gf/gf_task.h>
#include <gf/gf_heap_manager.h>
#include <if/if_mngr.h>
#include <mu/mu_object.h>
#include <mt/mt_matrix.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <nw4r/g3d/g3d_obj.h>

struct FinalObjectCallback {
    void* vtable;
    Vec3f position;
    unsigned char applied;
    unsigned char alignment[3];
};
struct MarthFinalInterface {
    gfTask task;
    // ResFile's single pointer is initialized directly in this C ABI entry.
    nw4r::g3d::ResFileData* resource;
    unsigned long resourceState;
    nw4r::g3d::ScnGroup* scene;
    MuObject* models[1];
    nw4r::g3d::G3dObj* sceneObjects[1];
    unsigned char initialized;
    unsigned char interfaceState[0x1b];
    void* connectedInterface;
    FinalObjectCallback callback;
    unsigned char visible;
    unsigned char alignment[3];
};
static_assert(sizeof(FinalObjectCallback) == 0x14, "Callback ABI");
static_assert(sizeof(MarthFinalInterface) == 0x8c, "Final interface ABI");
struct FinalModelInfo {
    const char* name;
    unsigned char first, end, priority, reserved;
};
struct FinalAnimationInfo {
    float start, end, rate;
    const char* name;
    unsigned char flags[4];
};
struct FinalTypeInfo { const char* name; const void* bases; };
struct FinalBaseInfo { const void* type; int adjustment; const void* end; };
typedef void (*FinalMethod)();
struct FinalTaskVtable { const void* type; unsigned long reserved; FinalMethod methods[23]; };
struct FinalCallbackVtable { const void* type; unsigned long reserved; FinalMethod methods[6]; };
// The manager header leaves the scene-list owner in its opaque leading region.
struct FinalManagerView { unsigned char reserved[0x14]; nw4r::g3d::ScnGroup* scene; };

extern "C" {
extern const FinalModelInfo lbl_106_rodata_50;
extern const float lbl_106_rodata_58, lbl_106_rodata_5C;
extern char lbl_106_data_56F0[], lbl_106_data_5703[], lbl_106_data_5730[];
extern char lbl_106_data_57C4[], lbl_106_data_57F0[];
extern const char lbl_106_data_28[];
extern FinalAnimationInfo lbl_106_data_571C;
extern FinalTaskVtable lbl_106_data_5740;
extern FinalCallbackVtable lbl_106_data_57A4;
extern FinalBaseInfo lbl_106_data_57DC, lbl_106_data_580C;
extern FinalTypeInfo lbl_106_data_57E8;
// Imported constructor/destructor entry points carry the existing task ABI.
gfTask* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(gfTask*, const char*, gfTask::Category, int, int, bool);
gfTask* __dt__6gfTaskFv(gfTask*, short);
void fn_800DB360(Vec3f*, const Vec3f*, int);
void fn_801AAF04(nw4r::g3d::ScnObj*, int, Matrix*);
nw4r::g3d::ScnGroup* fn_801AB6CC(MEMAllocator*, void*, int);
void fn_801AB038(nw4r::g3d::ScnObj*, int);
void fn_801AB0B8(nw4r::g3d::ScnObj*, int);
void fn_800B6838(MuObject*, const Vec3f*);
void fn_800B6CA4(Vec3f*, MuObject*);
void fn_800B3C5C(MuObject*, const FinalAnimationInfo*, int);
Vec3f* fn_106_D4E4(Vec3f*, const Vec3f*);
MarthFinalInterface* fn_106_D590(MarthFinalInterface*, void*);
FinalObjectCallback* fn_106_D62C(FinalObjectCallback*, short);
void fn_106_D66C(MarthFinalInterface*, nw4r::g3d::ResFile*, nw4r::g3d::ScnGroup*, int, Heaps::HeapType);
void fn_106_D73C(MarthFinalInterface*);
void fn_106_D820(MarthFinalInterface*, nw4r::g3d::ResFile*, int, Heaps::HeapType);
void fn_106_D92C(MarthFinalInterface*);
void fn_106_D720(IfMngr*, nw4r::g3d::ScnObj*);
void fn_106_DA78(IfMngr*, nw4r::g3d::ScnObj*);
}

static inline nw4r::g3d::ScnObj* finalSceneModel(MuObject* model) {
    return model->m_sceneModel;
}

extern "C" void fn_106_D410(FinalObjectCallback* callback, int timing, nw4r::g3d::ScnObj* object) {
    if (timing == 1 && !callback->applied) {
        Matrix matrix(true);
        Vec3f position;
        Vec3f rotation;
        Vec3f scale(lbl_106_rodata_58, lbl_106_rodata_58, lbl_106_rodata_58);
        Vec3f projected;
        fn_800DB360(&projected, &callback->position, 2);
        fn_106_D4E4(&position, &projected);
        float zero = lbl_106_rodata_5C;
        matrix.setIdentity();
        rotation.m_x = lbl_106_rodata_5C;
        rotation.m_y = lbl_106_rodata_5C;
        rotation.m_z = zero;
        matrix.setSRT(scale, rotation, position);
        fn_801AAF04(object, 0, &matrix);
        callback->applied = 1;
    }
}
#pragma dont_inline on
extern "C" Vec3f* fn_106_D4E4(Vec3f* destination, const Vec3f* source) {
    destination->m_x = source->m_x;
    destination->m_y = source->m_y;
    destination->m_z = source->m_z;
    return destination;
}
#pragma dont_inline reset
extern "C" MarthFinalInterface* fn_106_D500(void* data, Heaps::HeapType heap, int priority) {
    MarthFinalInterface* interface = static_cast<MarthFinalInterface*>(operator new(sizeof(MarthFinalInterface), heap));
    if (interface) interface = fn_106_D590(interface, data);
    nw4r::g3d::ResFile::Init(&interface->resource);
    nw4r::g3d::ScnGroup* scene = fn_801AB6CC(gfHeapManager::getMEMAllocator(heap), 0, 1);
    fn_106_D66C(interface, reinterpret_cast<nw4r::g3d::ResFile*>(&interface->resource), scene, priority, heap);
    return interface;
}
extern "C" MarthFinalInterface* fn_106_D590(MarthFinalInterface* interface, void* data) {
    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(&interface->task, lbl_106_data_5730, gfTask::Category_Info, 14, 6, true);
    *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(&interface->task) + 0x3c) = &lbl_106_data_5740;
    interface->resource = static_cast<nw4r::g3d::ResFileData*>(data);
    interface->resourceState = 0;
    interface->callback.vtable = &lbl_106_data_57A4;
    interface->callback.position.m_x = lbl_106_rodata_5C;
    interface->callback.position.m_y = lbl_106_rodata_5C;
    interface->callback.position.m_z = lbl_106_rodata_5C;
    interface->callback.applied = 0;
    interface->visible = 0;
    interface->initialized = 0;
    interface->connectedInterface = 0;
    return interface;
}
#pragma dont_inline on
extern "C" FinalObjectCallback* fn_106_D62C(FinalObjectCallback* callback, short deleting) {
    if (callback && deleting > 0) operator delete(callback);
    return callback;
}
#pragma dont_inline reset
extern "C" void fn_106_D66C(MarthFinalInterface* interface, nw4r::g3d::ResFile* resource,
        nw4r::g3d::ScnGroup* scene, int priority, Heaps::HeapType heap) {
    reinterpret_cast<unsigned char*>(&interface->task)[0x2c] &= ~2;
    fn_106_D73C(interface);
    fn_106_D820(interface, resource, priority, heap);
    interface->scene = scene;
    nw4r::g3d::ScnObj* model = finalSceneModel(interface->models[0]);
    scene->Insert(scene->sceneItemsCount, model);
    nw4r::g3d::ScnGroup* parent = reinterpret_cast<FinalManagerView*>(g_IfMngr)->scene;
    parent->Insert(parent->sceneItemsCount, reinterpret_cast<nw4r::g3d::ScnObj*>(scene));
    interface->visible = 1;
}
#pragma dont_inline on
extern "C" void fn_106_D720(IfMngr* manager, nw4r::g3d::ScnObj* object) {
    nw4r::g3d::ScnGroup* scene = reinterpret_cast<FinalManagerView*>(manager)->scene;
    scene->Insert(scene->sceneItemsCount, object);
}
extern "C" void fn_106_D73C(MarthFinalInterface* interface) {
    interface->scene = 0;
    for (int i = 0; i < 1; ++i) interface->models[i] = 0;
    for (int i = 0; i < 1; ++i) interface->sceneObjects[i] = 0;
}
#pragma dont_inline reset
extern "C" MarthFinalInterface* fn_106_D790(MarthFinalInterface* interface, short deleting) {
    if (interface) {
        *reinterpret_cast<void**>(reinterpret_cast<unsigned char*>(&interface->task) + 0x3c) = &lbl_106_data_5740;
        fn_106_D92C(interface);
        if (interface->scene) reinterpret_cast<nw4r::g3d::G3dObj*>(interface->scene)->Destroy();
        fn_106_D62C(&interface->callback, -1);
        __dt__6gfTaskFv(&interface->task, 0);
        if (deleting > 0) operator delete(interface);
    }
    return interface;
}
extern "C" void fn_106_D820(MarthFinalInterface* interface, nw4r::g3d::ResFile* resource, int priority, Heaps::HeapType heap) {
    int i;
    int j;
    const FinalModelInfo* info = &lbl_106_rodata_50;
    for (i = 0; i < 1; ++i, ++info) {
        int count = info->first < info->end ? info->end - info->first : 1;
        for (j = 0; j < count; ++j) {
            interface->models[info->first + j] = MuObject::create(resource, info->name, info->priority + priority, 0, heap);
            interface->models[info->first + j]->m_modelAnim->setUpdateRate(lbl_106_rodata_5C);
        }
    }
    nw4r::g3d::ScnObj* model = interface->models[0]->m_sceneModel;
    *reinterpret_cast<FinalObjectCallback**>(reinterpret_cast<unsigned char*>(model) + 0xd4) = &interface->callback;
    fn_801AB038(model, 1);
    fn_801AB0B8(model, 1);
}
extern "C" void fn_106_D92C(MarthFinalInterface* interface) {
    for (int i = 0; i < 1; ++i) {
        if (interface->sceneObjects[i]) {
            interface->sceneObjects[i]->Destroy();
            interface->sceneObjects[i] = 0;
        }
    }
    for (int i = 0; i < 1; ++i) {
        if (interface->models[i]) {
            delete interface->models[i];
            interface->models[i] = 0;
        }
    }
}
// Empty inherited hooks and callback phases in the original interface.
extern "C" void fn_106_D9DC(MarthFinalInterface*) {}
extern "C" void fn_106_D9E0(MarthFinalInterface* interface) {
    if (!interface->visible) {
        fn_106_D720(g_IfMngr, reinterpret_cast<nw4r::g3d::ScnObj*>(interface->scene));
        interface->visible = 1;
    }
}
extern "C" void fn_106_DA2C(MarthFinalInterface* interface, int) {
    if (interface->visible == 1) {
        fn_106_DA78(g_IfMngr, reinterpret_cast<nw4r::g3d::ScnObj*>(interface->scene));
        interface->visible = 0;
    }
}
#pragma dont_inline on
extern "C" void fn_106_DA78(IfMngr* manager, nw4r::g3d::ScnObj* object) {
    nw4r::g3d::ScnGroup* scene = reinterpret_cast<FinalManagerView*>(manager)->scene;
    if (!scene) return;
    scene->Remove(object);
}
#pragma dont_inline reset
extern "C" void fn_106_DA94(MarthFinalInterface*) {}
extern "C" void fn_106_DA98(MarthFinalInterface* interface, const Vec3f* position, int index) {
    fn_800B6838(interface->models[index], position);
}
extern "C" Vec3f* fn_106_DAA8(MarthFinalInterface* interface, const Vec3f* position) {
    return fn_106_D4E4(&interface->callback.position, position);
}
extern "C" void fn_106_DAB0(Vec3f* position, MarthFinalInterface* interface, int index) {
    fn_800B6CA4(position, interface->models[index]);
}
extern "C" void fn_106_DAC0(MarthFinalInterface* interface, int index) {
    fn_800B3C5C(interface->models[index], &lbl_106_data_571C, 0);
}
extern "C" void fn_106_DADC(MarthFinalInterface* interface, unsigned int visible) {
    if (visible == 1 && !interface->visible) {
        fn_106_D720(g_IfMngr, reinterpret_cast<nw4r::g3d::ScnObj*>(interface->scene));
        interface->visible = 1;
    } else if (visible == 0 && interface->visible == 1) {
        fn_106_DA78(g_IfMngr, reinterpret_cast<nw4r::g3d::ScnObj*>(interface->scene));
        interface->visible = 0;
    }
}
extern "C" unsigned long fn_106_DB60(MarthFinalInterface* interface) { return interface->callback.applied; }
extern "C" void fn_106_DB68() {}
extern "C" void fn_106_DB6C() {}
extern "C" void fn_106_DB70() {}
extern "C" void fn_106_DB74() {}
extern "C" {
void processBegin__6gfTaskFv(); void processAnim__6gfTaskFv(); void processUpdate__6gfTaskFv();
void processPreMapCorrection__6gfTaskFv(); void processMapCorrection__6gfTaskFv(); void processFixPosition__6gfTaskFv();
void processPreCollision__6gfTaskFv(); void processCollision__6gfTaskFv(); void processCatch__6gfTaskFv();
void processHit__6gfTaskFv(); void processCamera__6gfTaskFv(); void processFixCamera__6gfTaskFv();
void processEffect__6gfTaskFv(); void processGameProc__6gfTaskFv(); void processEnd__6gfTaskFv();
void renderPre__6gfTaskFv(); void renderOpa__6gfTaskFv(); void renderXlu__6gfTaskFv();
void processDebug__6gfTaskFv(); void renderDebug__6gfTaskFv(); void init__6gfTaskFv();
char lbl_106_data_56F0[] = "InfWeapon0017_TopN";
char lbl_106_data_5703[] = "InfWeapon0017_TopN__0";
FinalAnimationInfo lbl_106_data_571C = { 0.0f, 60.0f, 0.0f, lbl_106_data_5703, { 8, 0, 0, 0 } };
char lbl_106_data_5730[] = "IfMarthFinal";
FinalTaskVtable lbl_106_data_5740 = { lbl_106_data_28, 0, {
    reinterpret_cast<FinalMethod>(fn_106_D9DC), processBegin__6gfTaskFv, processAnim__6gfTaskFv,
    processUpdate__6gfTaskFv, processPreMapCorrection__6gfTaskFv, processMapCorrection__6gfTaskFv,
    processFixPosition__6gfTaskFv, processPreCollision__6gfTaskFv, processCollision__6gfTaskFv,
    processCatch__6gfTaskFv, processHit__6gfTaskFv, processCamera__6gfTaskFv,
    processFixCamera__6gfTaskFv, processEffect__6gfTaskFv, processGameProc__6gfTaskFv,
    processEnd__6gfTaskFv, renderPre__6gfTaskFv, renderOpa__6gfTaskFv, renderXlu__6gfTaskFv,
    processDebug__6gfTaskFv, renderDebug__6gfTaskFv, init__6gfTaskFv,
    reinterpret_cast<FinalMethod>(fn_106_D790) } };
FinalCallbackVtable lbl_106_data_57A4 = { &lbl_106_data_57E8, 0, {
    reinterpret_cast<FinalMethod>(fn_106_D62C), reinterpret_cast<FinalMethod>(fn_106_D410),
    fn_106_DB74, fn_106_DB70, fn_106_DB6C, fn_106_DB68 } };
char lbl_106_data_57C4[] = "IfMarthFinalObjCallback";
FinalBaseInfo lbl_106_data_57DC = { &lbl_106_data_580C, 0, 0 };
FinalTypeInfo lbl_106_data_57E8 = { lbl_106_data_57C4, &lbl_106_data_57DC };
char lbl_106_data_57F0[] = "nw4r::g3d::IScnObjCallback";
FinalBaseInfo lbl_106_data_580C = { lbl_106_data_57F0, 0, 0 };
extern const FinalModelInfo lbl_106_rodata_50 = { lbl_106_data_56F0, 0, 0, 0x80, 0 };
extern const float lbl_106_rodata_58 = 1.0f;
extern const float lbl_106_rodata_5C = 0.0f;
}
