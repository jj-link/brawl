#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct PeachSubArray {
    u32 off;
    u32 size;
    u32 max_size;
};

struct PeachArrayAggregate {
    soArrayFixed<u32>* vtable;
    PeachSubArray cache;
    PeachSubArray a;
    PeachSubArray b;
    PeachSubArray c;
};

extern "C" {

extern const u32 lbl_103_data_1C90[8];

void fn_103_8D88(PeachArrayAggregate* arrays, u32 off, u32 size, u32 max_size)
{
    arrays->vtable = (soArrayFixed<u32>*)lbl_103_data_1C90;
    arrays->a.off = off;
    arrays->a.size = size;
    arrays->a.max_size = max_size;
}

}