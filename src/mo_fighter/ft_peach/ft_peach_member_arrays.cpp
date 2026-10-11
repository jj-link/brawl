#include <so/so_array.h>
#include <types.h>

extern "C" {
const u32& fn_103_B348(const u8* fighter, s32 index) {
    const soArrayFixed<u32>* array = reinterpret_cast<const soArrayFixed<u32>*>(fighter + 0x18154);
    return array->at(index);
}

const void* fn_103_B35C(const u8* fighter) {
    return fighter + 0x18190;
}

const void* fn_103_B368(const u8* fighter) {
    return fighter + 0x18648;
}
}
