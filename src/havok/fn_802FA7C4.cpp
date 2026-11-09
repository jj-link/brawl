#pragma force_active on
#pragma use_lmw_stmw on
typedef int s32;
typedef unsigned int u32;
typedef unsigned short s16;
typedef unsigned char u8;
struct List { void** data; s32 count; u32 cap; };
struct Obj { char pad0[0x22]; s16 unk22; char pad24[2]; u8 unk26; u8 unk27; char pad28[0x60 - 0x28]; List list; };
struct Ctx { char pad0[0x40]; Obj** arr; s32 count; };
extern "C" {
void fn_8027CD94(void*, s32, s32);
void fn_802FA940(Ctx*, Obj*);
void fn_802FAABC(Ctx*, Obj*);
}
inline bool empty(Ctx* ctx) { return ctx->count == 0; }
extern "C" void fn_802FA7C4(Ctx* ctx) {
    s32 big = 0x10000;
    while (*(void**)((char*)ctx + 0x44) != 0) {
        Obj* obj = ctx->arr[ctx->count - 1];
        --ctx->count;
        if (obj != 0) {
            obj->unk22 = big - 1;
            if ((obj->unk26 >> 4) & 3) {
                List* lst = &obj->list;
                s32 w = -1;
                s32 j = 0;
                for (; j < lst->count; j++) {
                    if (lst->data[j] == 0) {
                        w = j;
                        j++;
                        break;
                    }
                }
                                while (j < lst->count) {
                    void* v = lst->data[j];
                    if (v != 0) {
                        lst->data[w++] = v;
                    }
                    j++;
                }
                if (w != -1) {
                    s32 cap = lst->cap & 0x3FFFFFFF;
                    if (cap < w) {
                        fn_8027CD94(lst, (w < cap * 2) ? cap * 2 : w, 4);
                    }
                    lst->count = w;
                }
                obj->unk26 = obj->unk26 & ~0x30;
            }
            u32 t = (obj->unk27 >> 6) & 3;
            if (t != (u32)(obj->unk26 & 3)) {
                if (t != 0) fn_802FA940(ctx, obj);
                else fn_802FAABC(ctx, obj);
            }
        }
    }
}