#pragma force_active on
#pragma fp_contract on
#pragma use_lmw_stmw on

struct Vec { float x, y, z, w; } __attribute__((aligned(16)));

extern "C" {
void fn_802879F8(void*, void*, void*);
void fn_80287A64(void*, void*, void*);
void fn_80294740(void*, void*);
void* fn_8029E668(void*);
void* fn_802DB588(void*);
void fn_802DB598(void*);
void* fn_802DB624(void*);
void fn_802DC6F8(void*, void*, void*);
void fn_802E67C8(void*, void*, void*, void*);
void* fn_802E6D08(int, int);
unsigned int fn_802E6F38(void*);
void fn_802E6F40(void*, void*);
void fn_802E6F8C(void*, void*);
void* fn_802E7868(void*);
void fn_802E7870(void*, void*);
}

extern "C" void fn_802E7554(void* arg0, char* arg1, int* list, int arg3, int arg4) {
    char* src = arg1;
    int i;
    char* temp;
    Vec v40, v30, v20, v10;

    for (i = arg3 - 1; i >= 0; list++, src += 0x80, i--) {
        temp = (char*)fn_802E6D08(*list, arg4);
        switch (fn_802E6F38(temp + 8)) {
        case 0:
        case 8:
            fn_80294740(temp + 0xE0, fn_8029E668(src));
            fn_802DC6F8(temp + 0xF0, fn_802DB624(fn_802DB588(temp)), fn_802E7868(src));
            fn_802E7870(temp, *(void**)(src + 4));
            fn_802DB598(&v40);
            fn_802DB598(&v30);
            fn_80287A64(&v30, fn_802DB624(fn_802DB588(temp)), temp + 0xF0);
            fn_802DB598(&v20);
            fn_802E6F40(&v20, temp + 0xD0);
            fn_802E6F8C(&v30, &v20);
            fn_802879F8(&v40, fn_802DB624(fn_802DB588(temp)), &v30);
            fn_802E67C8(arg0, temp + 0xE0, temp + 0xF0, temp + 0x10);
            fn_80294740(temp + 0xE0, src + 0x10);
            fn_802DB598(&v10);
            fn_80287A64(&v10, fn_802DB624(fn_802DB588(temp)), &v40);
            fn_802E6F8C(&v10, temp + 0xD0);
            fn_802879F8(temp + 0xF0, fn_802DB624(fn_802DB588(temp)), &v10);
            break;
        case 5:
            fn_802879F8(fn_802E7868(src), fn_802DB624(fn_802DB588(temp)), fn_802E7868(src));
            fn_80294740(src + 0x20, fn_802E7868(src));
            fn_80294740(src + 0x10, fn_8029E668(src));
            goto block8;
        case 3:
            fn_80294740(src + 0x20, fn_802E7868(src));
            fn_80294740(src + 0x10, fn_8029E668(src));
            goto block8;
        case 6:
            fn_80294740(src + 0x10, temp + 0xE0);
            fn_80294740(src + 0x20, temp + 0xF0);
            fn_80294740(fn_8029E668(src), temp + 0xE0);
            fn_80294740(fn_802E7868(src), temp + 0xF0);
            goto block9;
        case 4:
            fn_802879F8(fn_802E7868(src), fn_802DB624(fn_802DB588(temp)), fn_802E7868(src));
            fn_802DC6F8(src + 0x20, fn_802DB624(fn_802DB588(temp)), src + 0x20);
            goto block8;
        case 2:
        block8:
            fn_802E7870(temp, *(void**)(src + 4));
        block9:
            fn_802E67C8(arg0, fn_8029E668(src), fn_802E7868(src), temp + 0x10);
            fn_80294740(temp + 0xE0, src + 0x10);
            fn_80294740(temp + 0xF0, src + 0x20);
            break;
        }
    }
}
