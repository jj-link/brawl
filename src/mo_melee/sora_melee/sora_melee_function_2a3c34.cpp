#pragma force_active on
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_27_2A7970(void* self, s32 item, s32 a, s32 b);
extern "C" s32 fn_27_2B2B4C(void* arg);
extern "C" s32 fn_27_2C197C(void* root);
extern "C" void fn_27_2B2358(void* self);

class ItemList {
public:
    virtual void v2();
    virtual s32* at(s32 index);
    virtual void v4();
    virtual s32 size();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void clear();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void remove(s32 index);
    char storage[0x34];
};

struct ElemObj_base { char pad[0x14]; };
class ElemObj : public ElemObj_base {
public:
    virtual void method(s32 arg);
};

struct Mgr {
    char pad0[0x4c];
    s32 state;
    char pad1[0xc8 - 0x50];
    ItemList list_c8;
    char pad2[0x9e0 - 0xc8 - 0x38];
    ItemList list_9e0;
    char pad3[0x1170 - 0x9e0 - 0x38];
    ItemList list_1170;
    char pad4[0x14b5 - 0x1170 - 0x38];
    u8 flag;
    char pad5[2];
    void* root;
};

extern "C" void fn_27_2A3C34(Mgr* self) {
    u32 state = self->state;
    self->flag = 1;
    if (state > 2) {
        s32 i = 0;
        while (i < self->list_9e0.size()) {
            s32* p = self->list_9e0.at(i);
            if (*p != 0) {
                self->list_9e0.remove(i);
                fn_27_2A7970(self, *p, 0, 0);
                i--;
            }
            i++;
        }

        s32 count1 = 0;
        s32 j = 0;
        while (j < self->list_c8.size()) {
            s32 val = *self->list_c8.at(j);
            if (val != 0 && *(u8*)(val + 4) != 0) {
                count1++;
            }
            j++;
        }

        s32 count2 = 0;
        s32 k = 0;
        while (k < self->list_1170.size()) {
            s32* p = self->list_1170.at(k);
            s32 val = *p;
            if (val != 0 && *(u8*)(val + 0x10) != 0) {
                if (fn_27_2B2B4C((void*)val)) {
                    val = *p;
                    if (val != 0) {
                        ((ElemObj*)val)->method(1);
                    }
                    self->list_1170.remove(k);
                    k--;
                } else {
                    count2++;
                }
            }
            k++;
        }

        s32 r27 = 0;
        if (count1 <= 0 && count2 <= 0) {
            r27 = 1;
        }

        if (self->root && !fn_27_2C197C(self->root)) {
            r27 = 0;
        }

        if (self->state == 3) {
            if (r27 != 0) {
                self->state = 4;
            }
        } else if (self->state == 4) {
            self->state = 2;
        }

        s32 m = 0;
        while (m < self->list_c8.size()) {
            s32 val = *self->list_c8.at(m);
            if (val != 0) {
                fn_27_2B2358((void*)val);
            }
            m++;
        }
    }
}