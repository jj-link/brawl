#pragma force_active on
typedef unsigned char u8;
typedef void (*FnPtr)(void*, void*, void*, void*, void*, void*, void*);

void fn_8037BDD4(u8* self, void* a, void* b)
{
    FnPtr f = *(FnPtr*)(self + 0x40);
    if (f == 0) {
        return;
    }
    f(*(void**)(self + 0x4), *(void**)(self + 0x10), a, b,
      *(void**)(self + 0x124), *(void**)(self + 0x128), *(void**)(self + 0x48));
}
