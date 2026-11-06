#pragma force_active on
#include <gf/gf_application.h>
#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <ut/ut_list.h>
#include <nw4r/g3d/g3d_obj.h>

class Object_vptr_0 { public: virtual void slot0(int); };
struct Object_vptr_14_base { char pad[0x14]; };
class Object_vptr_14 : public Object_vptr_14_base { public: virtual void slot0(int); };
struct Object5C_base { char pad[0x5c]; };
class Object5C : public Object5C_base { public: virtual void slot0(int); };

extern "C" {
void fn_800B8EDC(void*, void*);
void fn_800F95D8(void*);
void fn_8000E590(void*, int, unsigned);
void fn_800B8A0C(void*, int);
void fn_800AD87C(void*, int);
void fn_80106208(void*);
void fn_800C1D2C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), int, int);
void fn_800FABEC(void*, void*);
void fn_800FAEB8(void*, int);
void __dl__FPv(void*);
extern char lbl_8045CD90[], lbl_8045B4B8[], lbl_8045C4BC[];
extern utList lbl_8049E550;
extern char* g_gfSceneRoot;
}
struct ListData { Object_vptr_14* head; void* tail; int count; };
extern "C" ListData lbl_8049E560;

#define PTR(off) (*(void**)(s + (off)))
#define OBJ(off) (*(Object5C**)(s + (off)))
#define SIMPLE(off) (*(Object_vptr_0**)(s + (off)))
#define DEL5(off) if ((void*)(s + (off))) { Object5C* o = OBJ(off); if (o) o->slot0(1); }
#define DEL0(off) if ((void*)(s + (off))) { Object_vptr_0* o = SIMPLE(off); if (o) o->slot0(1); }
#define DESTROY(off) if ((void*)(s + (off))) { nw4r::g3d::G3dObj* o = *(nw4r::g3d::G3dObj**)(s + (off)); if (o) o->Destroy(); PTR(off) = 0; }
#define NODE(off) if ((void*)(s + (off))) { if ((void*)(s + (off))) { lbl_8049E550.removeExist((utListNode*)(s + (off))); PTR((off)+8) = 0; if ((void*)(s + (off))) { if (PTR((off)+8)) { ((utList*)0)->removeExist((utListNode*)(s + (off))); PTR((off)+8) = 0; } } } }
#define FILEOBJ(off) if ((void*)(s + (off))) { PTR((off)+12) = lbl_8045B4B8; fn_800FABEC(s + (off), lbl_8045B4B8); ((gfFileIOHandle*)(s+(off)+16))->release(); ((gfFileIOHandle*)(s+(off)+16))->~gfFileIOHandle(); NODE(off); }
#define COMPLEX(off) if ((void*)(s + (off))) { PTR((off)+0x30) = lbl_8045C4BC; PTR((off)+0x10) = lbl_8045C4BC+8; fn_800FABEC(s+(off)+0x14, lbl_8045C4BC); PTR(off)=0; *(char*)(s+(off)+0x2c)=0; FILEOBJ((off)+0x14); NODE((off)+4); }
#define GROUP(off) if ((void*)(s+(off))) { DESTROY((off)+0x24); DEL0((off)+0x20); DEL5((off)+0x1c); __destroy_arr(s+(off)+0xc, fn_800C1D2C, 4, 4); }

extern "C" void* fn_80101F88(void* self, int flag) {
    char* s = (char*)self;
    if (self) {
        PTR(0x3c)=lbl_8045CD90;
        PTR(0x1b0)=lbl_8045CD90+0x7c;
        gfCallBack* cb = (gfCallBack*)self;
        if (self) cb = (gfCallBack*)(s+0x1ac);
        g_gfApplication->m_114.remove(cb);
        fn_800B8EDC(PTR(0x330), PTR(0x280));
        fn_800F95D8(PTR(0x32c));
        ListData* list = &lbl_8049E560;
        while (list->count) {
            Object_vptr_14* o = list->head;
            if (o) o->slot0(1);
        }
        fn_8000E590(g_gfSceneRoot, 8, 0);
        if ((void*)(s+0x330)) fn_800B8A0C(PTR(0x330), 1);
        if ((void*)(s+0x32c)) { gfTask* t = *(gfTask**)(s+0x32c); if (t) t->exit(); PTR(0x32c)=0; }
        if ((void*)(s+0x328)) fn_800AD87C(PTR(0x328), 1);
        if ((void*)(s+0x324)) { if (PTR(0x324)) fn_80106208(PTR(0x324)); PTR(0x324)=0; }
        DEL5(0x31c);
        if ((void*)(s+0x308)) { DESTROY(0x318); DEL0(0x314); DEL5(0x310); DEL0(0x30c); DEL5(0x308); }
        if ((void*)(s+0x300)) { DEL5(0x304); }
        GROUP(0x2d8);
        GROUP(0x2b0);
        GROUP(0x288);
        DESTROY(0x284);
        DEL5(0x280);
        DESTROY(0x27c);
        FILEOBJ(0x264);
        COMPLEX(0x230);
        COMPLEX(0x1fc);
        COMPLEX(0x1c8);
        if (self) fn_800FAEB8(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}