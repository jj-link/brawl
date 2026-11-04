#include <types.h>
#pragma force_active on

struct List { u8 data[12]; };
struct Work { void* a; u32 b; void* c; u32 d; };
struct Object { u8 pad[0x40]; List a[4]; List b[4]; u32 count; };

extern "C" bool fn_27_C1AF0(void*, int);
extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_27_C1D44(void*, void*, Work*, int);
extern "C" void fn_27_C1E74(void*, Work*);

extern "C" void fn_27_C17B4(Object* self)
{
    Work* work = (Work*)__alloca(self->count * sizeof(Work));
    int count = 0;
    for (int i = 0; i < 4; ++i) {
        void* p = 0;
        while ((p = fn_8015C1B0(self->a + i, p)) != 0) {
            if (fn_27_C1AF0(p, count) == 1) {
                *(u32*)((u8*)work + count * 16) = 0;
                *(u32*)((u8*)work + count * 16 + 8) = 0;
                ++count;
            }
        }
        p = 0;
        while ((p = fn_8015C1B0(self->b + i, p)) != 0) {
            if (fn_27_C1AF0(p, count) == 1) {
                *(u32*)((u8*)work + count * 16) = 0;
                *(u32*)((u8*)work + count * 16 + 8) = 0;
                ++count;
            }
        }
    }
    for (int i = 0; i < 4; ++i) {
        void* p = 0;
        while ((p = fn_8015C1B0(self->a + i, p)) != 0) {
            void* q = p;
            while ((q = fn_8015C1B0(self->a + i, q)) != 0)
                fn_27_C1D44(p, q, work, 1);
        }
    }
    for (int i = 0; i < 4; ++i) {
        void* p = 0;
        while ((p = fn_8015C1B0(self->a + i, p)) != 0)
            fn_27_C1E74(p, work);
    }
    for (int i = 0; i < 4; ++i) {
        void* p = 0;
        while ((p = fn_8015C1B0(self->b + i, p)) != 0) {
            void* q = 0;
            while ((q = fn_8015C1B0(self->a + i, q)) != 0)
                fn_27_C1D44(p, q, work, 0);
        }
    }
    for (int i = 0; i < 4; ++i) {
        void* p = 0;
        while ((p = fn_8015C1B0(self->b + i, p)) != 0)
            fn_27_C1E74(p, work);
    }
}
