#include <revolution/OS/OSError.h>
#pragma force_active on
extern char lbl_27_data_17E20[];
extern "C" int fn_27_8D3E4(void*);

class Object_vptr_4 {
public:
    virtual void slot0();
    virtual void** slot1(int);
    virtual void slot2();
    virtual int slot3();
};
struct Self { char pad[4]; Object_vptr_4 object; };
extern "C" void fn_27_C41E4(Self* self) {
    int n = self->object.slot3();
    for (int i = 0; i < n; ++i) {
        void* p = *self->object.slot1(i);
        if (p == 0)
            OSReport(lbl_27_data_17E20);
        else
            fn_27_8D3E4(p);
    }
}