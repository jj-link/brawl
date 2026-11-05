#include <types.h>
#pragma force_active on
class Class_80466278;
typedef int (*Callback)(Class_80466278*, void*);
class Class_80466278 {
public:
    virtual void fn_801AC270();
    virtual void fn_801AB9D8();
    virtual void fn_801AC1AC();
    virtual void fn_801AC328();
    virtual void fn_801AC2F8();
    virtual int fn_801AB788(Callback, void*, int);
    u8 pad[0xd8];
    Class_80466278** items;
    u32 unused;
    u32 count;
};
extern "C" int fn_801AB788(Class_80466278* self, Callback callback, void* arg, int flag) {
    if (flag) {
        for (u32 i = 0; i < self->count; i++) {
            if (self->items[i]->fn_801AB788(callback, arg, 0) == 1)
                return 1;
        }
        return callback(self, arg) == 1;
    }
    int result = callback(self, arg);
    if (result == 0) {
        for (u32 i = 0; i < self->count; i++) {
            if (self->items[i]->fn_801AB788(callback, arg, 0) == 1)
                return 1;
        }
        return 0;
    }
    return result == 1;
}