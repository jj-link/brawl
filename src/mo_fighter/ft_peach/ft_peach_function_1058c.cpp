#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

class Class_62C8 {
public:
    virtual void fn_103_D384();
    virtual void fn_103_D2C4();
    virtual void fn_103_D380();
    virtual void fn_103_D37C();
    virtual void fn_103_D378();
    virtual void fn_103_D374();
};
class Class_6464 {
public:
    virtual void fn_103_F4B4();
    virtual void fn_103_F340();
    virtual void fn_103_D380();
    virtual void fn_103_D37C();
    virtual void fn_103_D378();
    virtual void fn_103_D374();
};
class Class_66E8 {
public:
    virtual void fn_103_107C8();
    virtual void fn_103_FE40();
    virtual void fn_103_10438();
    virtual void fn_103_100D8();
    virtual void fn_103_D378();
    virtual void fn_103_D374();
};
struct Class_64DC_base { char pad[8]; };
class Class_64DC : public Class_64DC_base {
public:
    virtual void fn_103_FD14();
    virtual void fn_103_F7AC();
    virtual void fn_103_F7BC();
    virtual void fn_103_F764();
    virtual void* fn_103_FD84();
    virtual void fn_103_F4F4();
    virtual void fn_103_F8C0();
    virtual void fn_103_F974();
    virtual void fn_103_FCCC();
    virtual void fn_103_F7CC();
    virtual void* fn_103_F550(int, int, int);
};
struct Work {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual int get(unsigned int);
    virtual void set(int, unsigned int);
};
struct Modules { Class_64DC* object; char pad[0x60]; Work* work; };
struct Owner { char pad[0x28]; int heap; int getHeap() { return heap; } };
struct Fighter { char pad[8]; Owner* owner; char pad2[0xcc]; Modules* modules; };
struct Object { char pad[0x28]; int id; };
struct Record { char pad[0x28]; u8 flag : 1; };
extern "C" {
void fn_103_106E4(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
Object* fn_103_1088C(void*, int, int, int);
void fn_103_10CF4(void*, int);
extern char lbl_103_data_66D8[];
extern char lbl_103_data_21B8[];

int fn_103_1058C(void* self, Fighter* fighter) {
    if (fighter->modules->work->get(0x10000041)) {
        fn_103_106E4(self, fighter);
    }
    void* p = fighter->modules->object->fn_103_FD84();
    int n = fn_27_14DB04(__dynamic_cast(p, 0, lbl_103_data_66D8, lbl_103_data_21B8, 1));
    void* result = fighter->modules->object->fn_103_F550(n, 0, -1);
    if (result) {
        Object* object = fn_103_1088C(result, 0x1f, fighter->owner->getHeap(), 1);
        if (object) {
            fighter->modules->work->set(object->id, 0x10000041);
            if (((Record*)g_GameGlobal->getGlobalRecordMenuDatap())->flag == 1) {
                fn_103_10CF4(object, 2);
            } else {
                fn_103_10CF4(object, 0);
            }
            return 1;
        }
    }
    return 0;
}
}