#pragma force_active on

extern "C" {
void fn_801BC360(void*);
extern char lbl_80466C30[];
extern char lbl_80466C90[];
void fn_801CF3D8(void*);
void fn_801CD318(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
extern unsigned char lbl_805A0608;
extern char lbl_804DD080[];
void OSInitMutex(void*);
void fn_801C07F8(void*, void*, unsigned long, unsigned long);
}

struct Link {
    Link* next;
    Link* prev;
};

extern "C" void* fn_801CD1C4(void* self) {
    char* p = (char*)self;
    fn_801BC360(self);

    Link* link = (Link*)(p + 0x12c);
    *(int*)(p + 0x12c) = 0;
    *(int*)(p + 0x130) = 0;
    *(void**)p = lbl_80466C30;
    *(int*)(p + 0x74) = 0;
    *(int*)(p + 0x78) = 0;
    *(void**)(p + 0x7c) = lbl_80466C30 + 0x24;
    *(char*)(p + 0xb8) = 0;
    *(char*)(p + 0xb9) = 0;
    *(int*)(p + 0x10c) = 0;
    *(int*)(p + 0x110) = 0;
    *(char*)(p + 0x114) = 0;
    *(void**)(p + 0x108) = lbl_80466C90;
    *(int*)(p + 0x118) = 0;
    *(int*)(p + 0x11c) = 0;
    *(int*)(p + 0x124) = 0;
    *(int*)(p + 0x128) = 0;
    link->next = link;
    link->prev = link;
    *(int*)(p + 0x134) = 0;

    __construct_array(p + 0x138, fn_801CF3D8, fn_801CD318, 0x34, 0x20);

    *(int*)(p + 0x7bc) = 0;
    *(int*)(p + 0x7c0) = 0;

    if (!lbl_805A0608) {
        OSInitMutex(lbl_804DD080);
        lbl_805A0608 = 1;
    }

    fn_801C07F8(p + 0x134, p + 0x138, 0x680, 0x34);
    return self;
}
