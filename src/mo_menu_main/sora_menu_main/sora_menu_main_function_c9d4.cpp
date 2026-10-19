#pragma force_active on
extern "C" {
void fn_1_6DA0(void*, void*);
void exit__6gfTaskFv(void*);

int fn_2_C9D4(void* self)
{
    char* s = (char*)self;
    char* obj = *(char**)(s + 0x184);
    int state = *(int*)(obj + 0x44);
    switch (state)
    {
    case 3:
        exit__6gfTaskFv(obj);
        *(char**)(s + 0x184) = 0;
        fn_1_6DA0(*(char**)(s + 0x40), *(char**)(s + 0x178));
        return *(unsigned char*)(s + 0x250) ? 5 : 3;
    case 0:
        break;
    case 1:
    {
        int idx = *(int*)(obj + 0x140);
        *(int*)(s + 0x248) = *(int*)(obj + idx * 4 + 0x50);
        *(int*)(s + 0x24c) = *(int*)(obj + 0x12c);
        *(unsigned char*)(s + 0x250) = 1;
        break;
    }
    case 2:
        *(unsigned char*)(s + 0x250) = 0;
        break;
    default:
        break;
    }
    return *(int*)(s + 0x238);
}
}
