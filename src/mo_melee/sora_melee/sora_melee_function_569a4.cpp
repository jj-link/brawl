#include <snd/snd_system.h>
#pragma force_active on
class Class_5860 {
public:
    virtual void fn_27_565F0();
    virtual void fn_27_56888();
    virtual int fn_27_5680C(void*, int);
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
};
struct Object {
    char pad0[0x34];
    int field34;
    char pad38[8];
    int field40;
    Class_5860* field44;
    char pad48[0xc];
    int field54;
};
extern "C" int fn_27_569A4(Object* self, void* arg, unsigned int mode) {
    int id = self->field44->fn_27_5680C(arg, self->field40);
    if ((unsigned int)(id + 0x10000) == 0xffff)
        return -1;
    if (mode == 1)
        return g_sndSystem->playSE((SndID)id, -1, 0, 0, self->field54);
    return g_sndSystem->playSE((SndID)id, self->field34, 0, 0, self->field54);
}