#pragma force_active on
extern "C" {
void* fn_96_1D7E4(void*);

struct Object {
    virtual ~Object();
    virtual void f1();
    virtual void f2();
    virtual void f3(void*);
};

void fn_96_1DC44(void* owner) {
    Object* object = (Object*)fn_96_1D7E4(owner);
    if (object) {
        object->f3(*(void**)((char*)owner + 8));
    }
}
}
