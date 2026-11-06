#include <st/stage.h>
#pragma force_active on

extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long size, Heaps::HeapType heap);
extern "C" void* __construct_new_array(void* block, void (*ctor)(), void* dtor, unsigned long size, int count);
extern "C" void* memset(void* p, int c, unsigned long n);
extern "C" void fn_27_E54();

void Stage::initPosPokeTrainer(int unk1, int unk2)
{
    if (unk1 != 0) {
        switch (unk2) {
        case 0: {
            unsigned long count = (unsigned char)unk1 * 2;
            void* arr = __construct_new_array(
                __nwa__FUlQ25Heaps8HeapType(count * 12 + 16, (Heaps::HeapType)0xF),
                fn_27_E54, 0, 12, count);
            *(void**)((char*)this + 0xBC) = arr;
            memset(arr, 0, unk1 * 24);
            break;
        }
        case 1: {
            void* arr = __construct_new_array(
                __nwa__FUlQ25Heaps8HeapType(unk1 * 12 + 16, (Heaps::HeapType)0xF),
                fn_27_E54, 0, 12, unk1);
            *(void**)((char*)this + 0xBC) = arr;
            memset(arr, 0, (unsigned long)unk1 * 12);
            break;
        }
        default:
            return;
        }
        *(signed char*)((char*)this + 0xC1) = (signed char)unk1;
        *(signed char*)((char*)this + 0xC2) = (signed char)unk2;
    }
}
