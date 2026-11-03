#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <string.h>
#pragma force_active on

extern "C" int fn_800BA3D8(void*);
struct Masks { unsigned int a, b; };
extern Masks lbl_40_rodata_9D8[];
extern Masks lbl_40_rodata_9F8[];

static inline gfPadStatus getStatus(void* p) {
    gfPadStatus status;
    int index = fn_800BA3D8(p);
    if (index >= 0)
        g_gfPadSystem->getSysPadStatus(index, &status);
    else
        memset(&status, 0, sizeof(status));
    return status;
}

struct Entry { char bytes[0x150]; };
struct Self { char pad[0x970]; Entry entries[1]; };
extern "C" int fn_40_4068C(Self* self, int index, int flag) {
    char* p = self->entries[index].bytes;
    gfPadStatus status = getStatus(p);
    if (status.m_error != 0)
        return 0;
    Masks* masks = &lbl_40_rodata_9F8[status.m_controllerType];
    if (flag)
        masks = &lbl_40_rodata_9D8[status.m_controllerType];
    if (masks->a & *(unsigned int*)(p + 0x18))
        return 1;
    return (status.m_buttonsPressedThisFrame.bits & masks->b) != 0;
}