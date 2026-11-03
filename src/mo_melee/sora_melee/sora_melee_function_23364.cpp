#include <so/event/so_event_presenter.h>
#include <so/so_array.h>
#include <mt/mt_vector.h>
#pragma force_active on

template <class T> class soInterpolation;
class soModuleAccesser;

extern "C" void fn_27_2520C(void*, void*, void*, void*);
extern "C" char lbl_27_bss_A9C[], lbl_27_bss_A48[];
extern "C" void* __vt__21soStatusEventObserver[];
extern "C" void* __vt__22soAnimCmdEventObserver[];
extern "C" char lbl_27_data_2588[];
extern const float lbl_27_rodata_388, lbl_27_rodata_38C;

class Getter {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual int get();
};
class Observer {
public:
    virtual void addObserver(short, signed char);
    short id, type, link;
};
class soPostureModuleImpl {
public:
    char base[0x44];
    char status[0xc];
    char anim[0xc];
    soArray<soInterpolation<Vec3f> >* array;
    float rot;
    int sync;
    float scale, x, y, z;
    soPostureModuleImpl(soModuleAccesser*, soArray<soInterpolation<Vec3f> >*, soEventObserverRegistrationDesc*);
};

soPostureModuleImpl::soPostureModuleImpl(soModuleAccesser* accesser, soArray<soInterpolation<Vec3f> >* arr, soEventObserverRegistrationDesc* desc) {
    fn_27_2520C(this, accesser, lbl_27_bss_A9C, lbl_27_bss_A48);
    int id;
    if (desc->checkStatus() == true) {
        char* p = *(char**)((char*)accesser + 0xd8);
        p = *(char**)(p + 0x80);
        id = ((Getter*)(p + 8))->get();
    } else {
        id = -1;
    }
    int id2 = -1;
    Observer* o = (Observer*)status;
    o->id = -1;
    o->type = 4;
    o->link = -1;
    *(void**)o = __vt__21soStatusEventObserver;
    o->addObserver((short)id, 1);
    if (desc->checkAnimCmd() == true) {
        char* p = *(char**)((char*)accesser + 0xd8);
        p = *(char**)(p + 0x80);
        id2 = ((Getter*)(p + 8))->get();
    }
    Observer* a = (Observer*)anim;
    a->id = -1;
    a->type = 5;
    a->link = -1;
    *(void**)a = __vt__22soAnimCmdEventObserver;
    a->addObserver((short)id2, -1);
    *(void**)base = lbl_27_data_2588;
    *(void**)status = lbl_27_data_2588 + 0x94;
    *(void**)anim = lbl_27_data_2588 + 0xa4;
    array = arr;
    rot = lbl_27_rodata_388;
    sync = -1;
    scale = lbl_27_rodata_38C;
    x = lbl_27_rodata_388;
    y = lbl_27_rodata_388;
    z = lbl_27_rodata_388;
}