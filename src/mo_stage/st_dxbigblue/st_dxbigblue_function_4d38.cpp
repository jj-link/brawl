#include <types.h>
#include <string.h>
#pragma force_active on

extern "C" {
u32 GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(void* mdl);
void* GetResNode__Q34nw4r3g3d6ResMdlCFUl(void* mdl, u32 index);
}

extern "C" int setNode__9grGimmickFv(void* self);
extern char lbl_81_data_C40[];
extern char lbl_81_data_C48[];

extern "C" int fn_81_4D38(void* self) {
    char* obj;
    void* sp8;
    int ret;
    u32 n;
    u32 flag1;
    u32 flag2;
    u32 i;

    ret = setNode__9grGimmickFv(self);
    sp8 = 0;
    obj = *(char**)(*(char**)((char*)self + 0x44));
    if (obj == 0) {
        return ret;
    }
    sp8 = *(void**)(obj + 0xe8);
    if (sp8 == 0) {
        return ret;
    }
    flag1 = 0;
    flag2 = 0;
    i = 0;

    n = GetResNodeNumEntries__Q34nw4r3g3d6ResMdlFv(&sp8);
    for (; i != n; i++) {
        char* node = (char*)GetResNode__Q34nw4r3g3d6ResMdlCFUl(&sp8, i);
        if (flag1 == 0) {
            u32 off = *(u32*)(node + 0x8);
            char* name = off != 0 ? node + off : 0;
            if (strstr(name, lbl_81_data_C40) != 0) {
                *(u32*)((char*)self + 0x180) = node != 0 ? *(u32*)(node + 0xc) : 0;
                flag1 = 1;
            }
        }
        if (flag2 == 0) {
            u32 off = *(u32*)(node + 0x8);
            char* name = off != 0 ? node + off : 0;
            if (strstr(name, lbl_81_data_C48) != 0) {
                *(u32*)((char*)self + 0x184) = node != 0 ? *(u32*)(node + 0xc) : 0;
                flag2 = 1;
            }
        }
        if (flag1 == 1 && flag2 == 1) {
            break;
        }
    }
    return ret;
}
