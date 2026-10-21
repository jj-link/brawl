#pragma force_active on
struct Flags {
    unsigned char b7:1, b6:1, b5:1, b4:1, b3:1, b2:1, b1:1, b0:1;
};

struct Entry {
    int a, b, c, d, e, f;
    unsigned char x;
    Flags flags;
    unsigned char y;
    unsigned char pad[0x21];
};

struct View {
    int header[2];
    Entry entry;
};

struct Object {
    int a, b;
    Entry entries[16];
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_80026C10(void*);
void fn_80026C1C(void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __dt__14gfFileIOHandleFv(void*, int);
extern Object* lbl_805A0038;

void fn_80026B14() {
    if (lbl_805A0038 == 0) {
        unsigned char* obj = (unsigned char*)__nw__FUlQ25Heaps8HeapType(0x3C8, 1);
        if (obj != 0) {
            __construct_array(obj + 8, fn_80026C10, fn_80026C1C, 0x3C, 16);
            *(int*)(obj + 4) = 0;
            unsigned int i = 0;
            int offset = 0;
            do {
                ((View*)(obj + offset))->entry.a = 0;
                ((View*)(obj + offset))->entry.e = 0;
                ((View*)(obj + offset))->entry.b = 0;
                int handle = 0;
                ((View*)(obj + offset))->entry.f = 0;
                __dt__14gfFileIOHandleFv(&handle, -1);
                ((View*)(obj + i * 0x3C))->entry.d = 0;
                ((View*)(obj + i * 0x3C))->entry.flags.b6 = 0;
                ((View*)(obj + i * 0x3C))->entry.flags.b7 =
                    ((View*)(obj + i * 0x3C))->entry.flags.b5 =
                    ((View*)(obj + i * 0x3C))->entry.flags.b4 =
                    ((View*)(obj + i * 0x3C))->entry.flags.b3 = 0;
                ((View*)(obj + i * 0x3C))->entry.flags.b2 = 1;
                ((View*)(obj + i * 0x3C))->entry.y = 0;
                ++i;
                offset += 0x3C;
            } while (i < 16);
            *(int*)obj = 0xFF;
        }
        lbl_805A0038 = (Object*)obj;
    }
}
}
