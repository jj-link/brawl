#pragma force_active on
struct FnObj;
extern "C" FnObj* fn_125_9E50();

extern "C" FnObj* fn_125_9F3C(FnObj* self, int index)
{
    switch (index)
    {
    case 0:
        return self;
    case 1:
        return (FnObj*)((char*)self + 0x48C);
    case 2:
        return fn_125_9E50();
    default:
        return fn_125_9E50();
    }
}