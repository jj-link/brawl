#include <gf/gf_heap_manager.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on
struct MyVec { float x, y, z, w; } __attribute__((aligned(16)));
class Factory {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void* create();
    char pad[4];
    void* p;
};
struct Item { char pad[0x28]; Factory* factory; };
struct Context { char pad[0x198]; void* model; char pad19c[0x328]; Item** items; int count; };
class BodyInterface { public:
    virtual void vf0(); virtual void vf1(); virtual void vf2(); virtual void vf3(); virtual void vf4();
    virtual void vf5(); virtual void vf6(); virtual void vf7(); virtual void vf8(); virtual void vf9();
    virtual void vf10(); virtual void vf11(); virtual void vf12(); virtual void vf13(); virtual void vf14();
    virtual void set1(MyVec*); virtual void set2(MyVec*);
};
struct Body {
    char pad0[8]; void* p; char padc[0x2c]; int flag; char pad3c[0x64];
    BodyInterface interface; char pada4[0xb8]; float f15c; float f160;
};
struct Object { char pad[0x18]; char transform[12]; nw4r::g3d::ScnMdl* scene; Body* body; char pad2c[0x10]; char a,b,c,d; };
extern "C" {
extern Context* lbl_20_bss_8; extern void* lbl_805A0EC8;
extern const float lbl_20_rodata_1E0; extern const float lbl_20_rodata_1E4; extern const float lbl_20_rodata_1F0; extern const float lbl_20_rodata_1F8; extern const float lbl_20_rodata_358;
void* fn_8027EA20(void*,unsigned int,int); void fn_8027EABC(void*,void*,unsigned int,int);
nw4r::g3d::ScnMdl* fn_801B0B40(void*,void*,void*,int,int,void(*)()); void fn_801B0A28();
void fn_802EC1C0(void*,void*,int); void fn_802E1970(void*,void*); void fn_802E18B0(void*,void*); void fn_802E34D8(void*,MyVec*); void fn_802E1A54(void*); void fn_802CD4D8(void*,int,int); void fn_802EFD3C(void*,void*,bool*,int,int);
}
struct ItemArray { Item** data; int size; unsigned int capacity; ItemArray():data(0),size(0),capacity(0x80000000){} };
inline void copyElements(ItemArray* array, int size, Item** dst, Item** src) {
    int i=0;
    array->size=size;
    for(;i<size;++i) dst[i]=src[i];
}
inline unsigned int isOwned(const ItemArray& a) { return a.capacity & 0x80000000; }
inline void dealloc(ItemArray& a) { fn_8027EABC(lbl_805A0EC8, a.data, a.capacity << 2, 0x15); }
inline void freeItems(ItemArray& a) { if (!isOwned(a)) dealloc(a); }
inline void bindBody(Object* self) {
    Body* body = self->body;
    fn_802E1970(body,self->transform);
    char* transform = self->transform;
    if (transform != 0) transform += 4;
    fn_802E18B0(body,transform);
}
extern "C" void fn_20_D34C(Object* self) {
    Body* body;
    ItemArray array;
    Context* ctx=lbl_20_bss_8;
    int capacity = (int)(array.capacity&0x3fffffff);
    if(capacity<ctx->count) {
        if(!(array.capacity&0x80000000)) fn_8027EABC(lbl_805A0EC8,array.data,array.capacity*4,0x15);
        array.data=(Item**)fn_8027EA20(lbl_805A0EC8,ctx->count*4,0x15);
        array.capacity=ctx->count|(array.capacity&0x40000000);
    }
    copyElements(&array,ctx->count,array.data,ctx->items);
    void* allocator=gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2a);
    int out __attribute__((aligned(4)));
    void* model=ctx->model;
    void** modelPtr=&model;
    int* outPtr=&out;
    self->scene=fn_801B0B40(allocator,outPtr,modelPtr,0,1,fn_801B0A28);
    g_gfSceneRoot->add(gfSceneRoot::Layer_Ground,self->scene);
    self->body=(Body*)array.data[0]->factory->create();
    fn_802EC1C0(array.data[0]->factory->p,self->body,1);
    bindBody(self);
    MyVec q;
    Context** ctxptr = &lbl_20_bss_8;
    MyVec v;
    v.x=lbl_20_rodata_1E0; v.y=lbl_20_rodata_1F8; v.z=lbl_20_rodata_358; v.w=lbl_20_rodata_1E0;
    Context* ctx2=*ctxptr;
    fn_802E34D8(self->body,&v);
    Body* firstBody = self->body;
    firstBody->f15c=lbl_20_rodata_1F0;
    self->body->f160=lbl_20_rodata_1F0;
    q.x=lbl_20_rodata_1E0; q.y=lbl_20_rodata_1E0; q.z=lbl_20_rodata_1E0; q.w=lbl_20_rodata_1E4;
    body=self->body; fn_802E1A54(body); body->interface.set1(&q);
    q.x=lbl_20_rodata_1E0; q.y=lbl_20_rodata_1E0; q.z=lbl_20_rodata_1E0; q.w=lbl_20_rodata_1E4;
    body=self->body; fn_802E1A54(body); body->interface.set2(&q);
    self->body->flag=1;
    fn_802CD4D8((char*)ctx2+0x1a0,1,2);
    bool flag=true;
    bool* flagPtr = &flag;
    void* contextPtr = (char*)ctx2+0x1a0;
    fn_802EFD3C(self->body->p,contextPtr,flagPtr,0,1);
    self->a=0; self->c=0; self->d=0; self->b=0;
    freeItems(array);
}