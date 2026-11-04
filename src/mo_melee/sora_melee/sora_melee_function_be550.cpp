#include <types.h>
#pragma force_active on
extern "C" const float lbl_27_rodata_E80;
struct Entry {
    char pad[4];
    int id;
    char pad2[4];
    unsigned char kind;
    unsigned char type;
    char pad3[2];
    float x, y;
};
class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual void fn_27_14B80();
    virtual void fn_27_14B88();
    virtual void fn_27_16A70();
    virtual void fn_27_16AB8();
    virtual void fn_27_1CBB4();
    virtual void fn_27_14A20();
    virtual void fn_27_1CBAC();
    virtual void fn_27_1CBA4();
    virtual void fn_27_14B98();
    virtual void fn_27_14B90();
    virtual int fn_27_1CB88(int);
    virtual Entry* fn_27_14CF8(int, int);
};
struct Modules { char pad[0x90]; Class_1250* list; };
struct Object { char pad[0xd8]; Modules* modules; };
struct Result { int id, type; };
extern "C" int fn_27_BE550(void* self, Result* out, int flags, Object* object) {
    int count = object->modules->list->fn_27_1CB88(-1);
    if (count > 0) {
        float best = lbl_27_rodata_E80;
        int flag1 = flags & 1;
        int flag2 = flags & 2;
        Entry* selected = 0;
        for (int i = 0; i < count; i++) {
            Entry* entry = object->modules->list->fn_27_14CF8(-1, i);
            if (entry->kind == 3) {
                if (entry->type == 0x12 && flag1) {
                    float dist = entry->x * entry->x + entry->y * entry->y;
                    if (dist < best) {
                        best = dist;
                        selected = entry;
                    }
                } else if (entry->type == 0x13 && flag2) {
                    float dist = entry->x * entry->x + entry->y * entry->y;
                    if (dist < best) {
                        selected = entry;
                        best = dist;
                    }
                }
            }
        }
        if (selected) {
            if (selected->type == 0x12) out->type = 0;
            else if (selected->type == 0x13) out->type = 1;
            out->id = selected->id;
            return 1;
        }
    }
    return 0;
}