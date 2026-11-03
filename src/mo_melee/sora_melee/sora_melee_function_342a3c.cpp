#pragma force_active on
template <class T> struct soInstanceUnitFullProperty { char data[12]; ~soInstanceUnitFullProperty(); };

extern "C" {
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void* __dt__23soEventManageModuleImplFv(void*, short);
void fn_27_840D8(void*, int); void fn_27_84358(void*, int);
void fn_27_844D8(void*, int); void fn_27_84198(void*, int);
void fn_27_845D8(void*, int); void fn_27_84258(void*, int);
void fn_27_84458(void*, int); void fn_27_84398(void*, int);
void fn_27_50588(void*, int);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
extern char lbl_27_data_21D78[], lbl_27_data_260C8[], lbl_27_data_25948[];
extern char lbl_27_data_25F88[], lbl_27_data_25FD8[], lbl_27_data_26028[], lbl_27_data_26050[];
}
class soTurnEventObserver; class soLinkEventObserver;
template <class T> struct soEventUnitWrapper { static char __vt[]; };

struct LinkArray { char pad[12]; soInstanceUnitFullProperty<soLinkEventObserver*> a[1]; };
struct EventManager { virtual void fn0(); virtual void fn1(short); };
#define BLOCK(off, fn, count, vt) \
    if (p + off) { \
        if (p + off + 0xc && p + off + 0x1c) \
            __destroy_arr(p + off + 0x28, fn, 12, count); \
        if (p + off) { \
            if (p + off) { \
                short id = *(short*)(p + off + 4); \
                *(void**)(p + off) = vt; \
                if (id != -1) \
                    ((EventManager*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(short*)(p + off + 4)))->fn1(*(short*)(p + off + 6)); \
            } \
        } \
    }
extern "C" void* fn_27_342A3C(void* obj, int flag) {
    char* p = (char*)obj;
    if (p) {
        BLOCK(0x480, fn_27_840D8, 6, soEventUnitWrapper<soTurnEventObserver>::__vt)
        BLOCK(0x440, fn_27_84358, 1, lbl_27_data_21D78)
        BLOCK(0x3f8, fn_27_844D8, 2, lbl_27_data_260C8)
        BLOCK(0x39c, fn_27_84198, 4, lbl_27_data_25948)
        BLOCK(0x340, fn_27_845D8, 4, lbl_27_data_25F88)
        BLOCK(0x2e0, fn_27_84258, 4, lbl_27_data_25FD8)
        if (p + 0x2a8) {
            if (p + 0x2b4)
                ((LinkArray*)(p + 0x2c4))->~LinkArray();
            if (p + 0x2a8)
                if (p + 0x2a8) {
                    short id = *(short*)(p + 0x2ac);
                    *(void**)(p + 0x2a8) = soEventUnitWrapper<soLinkEventObserver>::__vt;
                    if (id != -1)
                        ((EventManager*)getManager__13soEventSystemFl(getInstance__13soEventSystemFv(), *(short*)(p + 0x2ac)))->fn1(*(short*)(p + 0x2ae));
                }
        }
        BLOCK(0x188, fn_27_84458, 20, lbl_27_data_26028)
        BLOCK(0xcc, fn_27_84398, 12, lbl_27_data_26050)
        __dt__23soEventManageModuleImplFv(p + 0xb8, -1);
        if (p && p + 0x14)
            __destroy_arr(p + 0x20, fn_27_50588, 8, 19);
        if (flag > 0) __dl__FPv(p);
    }
    return obj;
}