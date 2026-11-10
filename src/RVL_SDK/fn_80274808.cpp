#include <types.h>
#pragma force_active on

class Obj
{
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual Obj* f13(char*, s32);
    virtual Obj* f14(Obj*);
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18(s32);
};

struct Holder
{
    char pad[0x10];
    Obj* obj;
};

struct SelfObj
{
    s32 mode;
    char pad1[0x1E4];
    Holder* holder;
    char pad2[0x14];
    Obj* outer;
};

extern "C" {

extern char* lbl_80485C40[];

void fn_80274808(SelfObj* self)
{
    int i;
    char** p;
    switch (self->mode)
    {
    case 0:
        p = lbl_80485C40;
        i = 0;
        do
        {
            if (i < 2 || i == 9)
            {
                self->outer->f14(self->holder->obj->f13(*p, 1))->f18(1);
            }
            else
            {
                self->outer->f14(self->holder->obj->f13(*p, 1))->f18(0);
            }
            i++;
            p++;
        } while (i < 10);
        break;
    case 1:
        p = lbl_80485C40;
        i = 0;
        do
        {
            if (i > 0 && i < 7 || i == 9)
            {
                self->outer->f14(self->holder->obj->f13(*p, 1))->f18(1);
            }
            else
            {
                self->outer->f14(self->holder->obj->f13(*p, 1))->f18(0);
            }
            i++;
            p++;
        } while (i < 10);
        break;
    case 2:
        p = lbl_80485C40;
        i = 0;
        do
        {
            if (i < 7 || i == 9)
            {
                self->outer->f14(self->holder->obj->f13(*p, 1))->f18(0);
            }
            else
            {
                self->outer->f14(self->holder->obj->f13(*p, 1))->f18(1);
            }
            i++;
            p++;
        } while (i < 10);
        break;
    }
}

}