#include <types.h>
#include <so/event/so_event_system.h>
#pragma force_active on

extern "C" char lbl_27_data_5B30[];
extern "C" char lbl_27_data_5B3C[];
extern "C" char lbl_27_data_1180[];
class soAnimCmdEventObserver;
template <typename T> class soEventObserver {
public:
    static void __vt(int, int);
};
extern "C" void __dl__FPv(void*);

struct Blk { void* vt; s16 id; s16 a; s16 b; s16 pad; };
struct Obj { char pad0[4]; Blk b[4]; };

#define RELEASE(i, v) \
 if (&p->b[i] != 0 && &p->b[i] != 0) { \
 s16 id = p->b[i].id; p->b[i].vt = v; \
 if (soEventSystem::getInstance()->getInstanceManager().isContain(id) == 1U) \
 soEventSystem::getInstance()->getManager(p->b[i].id)->eraseObserver(p->b[i].a, p->b[i].b); \
 p->b[i].b = -1; p->b[i].id = -1; }

extern "C" void* fn_27_565F0(Obj* p, s32 flag) {
 if (p) {
 RELEASE(3, lbl_27_data_5B30);
 RELEASE(2, lbl_27_data_5B3C);
 RELEASE(1, (void*)soEventObserver<soAnimCmdEventObserver>::__vt);
 RELEASE(0, lbl_27_data_1180);
 if (flag > 0) __dl__FPv(p);
 }
 return p;
}