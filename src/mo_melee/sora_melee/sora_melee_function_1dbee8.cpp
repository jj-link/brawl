#pragma force_active on
class DispatchObject;
typedef void (DispatchObject::*DispatchMethod)(int, void*);

extern "C" const DispatchMethod lbl_27_rodata_27B8[3];

extern "C" void fn_27_1DBEE8(DispatchObject* self, int index, void* arg)
{
    if (index <= -1 || index >= 3)
        return;

    (self->*lbl_27_rodata_27B8[index])(index, arg);
}
