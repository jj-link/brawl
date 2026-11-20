#pragma force_active on
#pragma fp_contract on
#include <types.h>

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(void*, u32);
    virtual void slot2(void*, u32);
};

extern "C" {
float* fn_800966A4(u32, int);
void fn_80288B20(void*, void*, int);
void fn_8028965C(void*, void*);
void fn_802878F0(void*, void*, void*);
void fn_80294740(void*, void*);
float fn_80295128(void*, u32);
void fn_8029873C(void*, float);
void* fn_802DB624(void*);
void* fn_802DB8A0(void*, u32);
void fn_802DBB28(void*, void*);
u32 fn_802DBBB8(void*);
void fn_80282CD4(void*, void*, void*);
void fn_802DC144(void*, void*, void*, void*, void*, void*, void*);
void fn_802DC6F8(void*, void*, void*);
void fn_802DC764(void*, void*, void*, void*, void*, void*, void*);
void fn_802DC834(void*, void*);
void fn_802DC898(void*, void*, void*, void*, void*, void*, void*);
void fn_802DCA2C(void*, void*, void*, void*, void*, void*, void*);
void fn_802DCBD8(void*, void*, void*, void*, void*, void*, void*);
void fn_802DCCC8(void*, void*, void*, void*, void*, void*, void*);
void fn_802DCE20(void*, void*, void*, void*, void*, void*, void*);
void fn_802DCFE4(void*, void*, void*, void*, void*, void*, void*);
void fn_802DD0C8(void*, void*, void*, void*, void*, void*, void*);
void fn_802DD2C8(void*, void*, void*, void*, void*, void*, void*);
void fn_802DD45C(void*, void*, void*, void*, void*, void*, void*);
void fn_802DBFD0(void*, void*, void*, void*, void*, void*, void*);
void fn_802DD4F4(void*);
u32 fn_802DD4F8(void*);
u32 fn_802DD500(void*);
u32 fn_802DD508(void*);
}

extern "C" void fn_802DC23C(void* pa, void* pb, void* pc, void* pd) {
    struct State {
        char copy[0x54] __attribute__((aligned(16)));
        char pad2[0xC];
        char r80[0x20];
        char b[0x30];
        char pD0[0x30];
        char p100[0x30];
        u32 p130;
        u32 p134;
        u32 p138;
    } st;
    u32 item;
    u32 counter;
    u32 pp;
    u8* base = (u8*)pc;

    fn_8028965C(st.copy, pc);
    fn_802DD4F4(st.r80);
    st.p138 = 0;
    st.p130 = fn_802DBBB8(st.copy + 0x30);
    st.p134 = fn_802DBBB8(st.copy + 0x34);
    item = fn_802DD4F8((u8*)pb + 0x1c);
    counter = fn_802DD500((u8*)pb + 0x10);
    pp = fn_802DD508((u8*)pb + 0x28);

    while (true) {
        u32 cmd = *(u32*)item;
        switch (cmd) {
        case 3: {
            item += 4;
            void* m = fn_802DB8A0(st.b, *(u32*)item);
            fn_802DC6F8(m, fn_802DB624((void*)st.p130), (void*)counter);
            counter += 0x10;
            break;
        }
        case 4: {
            item += 4;
            void* m = fn_802DB8A0(st.b, *(u32*)item);
            fn_802DC6F8(m, fn_802DB624((void*)st.p134), (void*)counter);
            counter += 0x10;
            break;
        }
        case 5: {
            item += 4;
            fn_80294740(fn_802DB8A0(st.b, *(u32*)item), (void*)counter);
            counter += 0x10;
            break;
        }
        case 6:
            fn_802DC764(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 7:
            fn_802DBFD0(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 8: {
            u32 old = counter;
            counter += 0x30;
            fn_80282CD4(st.pD0, fn_802DB624((void*)st.p130), (void*)old);
            break;
        }
        case 9: {
            u32 old = counter;
            counter += 0x30;
            fn_80282CD4(st.p100, fn_802DB624((void*)st.p134), (void*)old);
            break;
        }
        case 10:
            fn_802DC834(st.pD0, fn_802DB624((void*)st.p130));
            break;
        case 11:
            fn_802DC834(st.p100, fn_802DB624((void*)st.p134));
            break;
        case 12:
            fn_802DC898(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 13:
            fn_802DCA2C(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 16:
            fn_802DCBD8(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 17:
            fn_802DCCC8(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 18:
            fn_802DCE20(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 19:
            fn_802DCFE4(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 14:
            fn_802DD0C8(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 15:
            fn_802DD2C8(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 20:
            fn_802DD45C(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 21:
            fn_802DC144(pa, (void*)&item, (void*)&counter, pb, st.r80, st.copy, pd);
            break;
        case 1:
            fn_802878F0(st.r80, (void*)st.p130, (void*)counter);
            counter += 0x10;
            break;
        case 2:
            fn_802878F0(st.r80 + 0x10, (void*)st.p134, (void*)counter);
            counter += 0x10;
            break;
        case 22: {
            float* ptr = fn_800966A4(counter, 0);
            u32 old = counter;
            float v = *ptr;
            counter += 0x10;
            fn_8029873C(st.copy + 0x20, v * fn_80295128(st.copy + 0x20, old));
            break;
        }
        case 23:
            fn_802DBB28(st.copy + 0x20, base + 0x20);
            break;
        case 24: {
            item += 4;
            Object_vptr_0* o = (Object_vptr_0*)*(u32*)pp;
            o->slot1(st.r80, *(u32*)item);
            pp += 4;
            break;
        }
        case 25: {
            item += 4;
            Object_vptr_0* o = (Object_vptr_0*)*(u32*)pp;
            o->slot2(st.r80, *(u32*)item);
            fn_80288B20(st.copy, pd, 1);
            pp += 4;
            break;
        }
        case 0:
            return;
        default:
            break;
        }
        item = item + 4;
    }
}