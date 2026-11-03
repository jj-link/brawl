#include <types.h>
#include <gr/collision/gr_collision.h>
#pragma force_active on

extern "C" void fn_80110CEC(void*);
extern "C" void fn_80110EA0(void*, float*);
extern "C" void fn_80110F7C(void*);
extern "C" void fn_8011135C(void*, void*);

extern "C" void fn_80112674(u8* self, unsigned int param) {
    nw4r::ut::LinkList<u8, 48>& list = *(nw4r::ut::LinkList<u8, 48>*)&g_grCollisionList;
    float box[4];
    if ((self[0x40] >> 3) & 1) {
        float a, b;
        b = *(float*)(self + 0x54);
        a = *(float*)(self + 0x48);
        box[0] = a;
        box[1] = b;
        float c, d;
        d = *(float*)(self + 0x50);
        c = *(float*)(self + 0x4c);
        box[2] = c;
        box[3] = d;
    }
    nw4r::ut::LinkList<u8, 48>::Iterator it = list.GetBeginIter();
    for (; it != list.GetEndIter(); ++it) {
        u8* obj = &*it;
        u8 flags = obj[0x2c];
        if ((flags >> 7 & 1) && param == (unsigned int)(flags >> 1 & 1)) {
            fn_80110CEC(obj);
            if ((self[0x40] >> 3) & 1)
                fn_80110EA0(obj, box);
            fn_80110F7C(obj);
        }
    }
    nw4r::ut::LinkList<u8, 48>::Iterator outer = list.GetBeginIter();
    for (; outer != list.GetEndIter(); ++outer) {
        u8* obj = &*outer;
        u8 flags = obj[0x2d];
        if ((flags >> 6 & 1) && param == (unsigned int)(obj[0x2c] >> 1 & 1) && (flags >> 5 & 1)) {
            nw4r::ut::LinkList<u8, 48>::Iterator inner = outer;
            ++inner;
            for (; inner != list.GetEndIter(); ++inner) {
                u8* otherObj = &*inner;
                if ((otherObj[0x2c] >> 7 & 1) && param == (unsigned int)(obj[0x2c] >> 1 & 1) &&
                    (obj[0x2d] >> 6 & 1) && (otherObj[0x2d] >> 5 & 1)) {
                    fn_8011135C(obj, otherObj);
                }
            }
        }
    }
}