#pragma force_active on
extern void fn_80252784(void*, short, short*);
extern void fn_802533C8(void*, int, int);

void fn_802565A8(void* obj) {
    int val = *(unsigned short*)((char*)obj + 0x14);
    switch (val) {
        case 11:
            fn_80252784(*(void**)((char*)obj + 0x10), 5, 0);
            break;
        case 12:
            fn_802533C8(*(void**)((char*)obj + 0x10), 5, 0);
            break;
    }
}
