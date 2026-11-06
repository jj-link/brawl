#include <types.h>
#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int* slot1(int);
    virtual void slot2();
    virtual int slot3();
};
struct Inner { char pad[4]; int value; };
struct Holder { char pad[0xd8]; Inner* inner; };
struct Arg { char pad[0x14]; u32 flags; };
struct Self {
    char pad[0x28];
    Holder* holder;
    Object_vptr_0* array;
    char pad30[4];
    float value;
    char pad38[0x88];
    char work[0x22];
    u8 flag;
};
extern "C" void fn_27_36074(void*, int, int, int);
extern "C" int fn_27_36028(void*, int, int);
extern "C" void fn_27_362E4(void*, int);
extern "C" void fn_27_36650(void*, int, int);
extern "C" void fn_27_4AD9C(int*, Arg*, int);
extern "C" void fn_27_4B088(int*, int, int, float);
extern "C" void fn_27_4B840(Self* self, int index, Arg* arg) {
    int i;
    fn_27_36074(self->work, index, (arg->flags >> 26) & 1, 0);
    int result = fn_27_36028(self->work, index, 0);
    if (*self->array->slot1(index) == 0) {
        int* p = self->array->slot1(index);
        *p = 1;
        fn_27_362E4(self->work, 0);
        i = 0;
        while (i < self->array->slot3()) {
            if (*self->array->slot1(i) != 0 && i != index)
                goto done;
            i++;
        }
        fn_27_36650(self->work, 0, 0);
    }
done:
    fn_27_4AD9C(self->array->slot1(index), arg, result);
    if (self->flag == 1) {
        int value = self->holder->inner->value;
        int* p = self->array->slot1(index);
        fn_27_4B088(p, value, result, self->value);
    }
}