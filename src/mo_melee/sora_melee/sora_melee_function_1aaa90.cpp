#include <types.h>
#pragma force_active on

extern "C" void fn_27_844D8(void*, int);
extern "C" void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" char lbl_27_data_260C8[];
extern "C" void* getInstance__13soEventSystemFv();
extern "C" void* getManager__13soEventSystemFl(void*, long);

class EventManager {
public:
    virtual void a();
    virtual void remove(s16);
};

class soArticleEventObserver;

template <typename T, s32 C>
class soEventUnitWithWorkArea {
public:
    u8 m_data[0x38];
    ~soEventUnitWithWorkArea();
};

template <typename T, s32 C>
soEventUnitWithWorkArea<T, C>::~soEventUnitWithWorkArea() {
    if ((u8*)this + 0xC != 0 && (u8*)this + 0x1C != 0) {
        __destroy_arr((u8*)this + 0x28, (void (*)(void*, int))fn_27_844D8, 0xC, 5);
    }
    if (this && this) {
        s16 id = *(s16*)((char*)this + 4);
        *(void**)this = (void*)lbl_27_data_260C8;
        if (id != -1) {
            ((EventManager*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), *(s16*)((char*)this + 4)))->remove(*(s16*)((char*)this + 6));
        }
    }
}

template class soEventUnitWithWorkArea<soArticleEventObserver, 5>;
