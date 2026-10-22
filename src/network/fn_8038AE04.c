#pragma force_active on
extern void fn_8035E00C(void*);
extern int closesocket(int);
extern int fn_8035A590(int);
extern void* fn_8035A598(int, int);
extern int fn_80388590(void*);
extern void* fn_8035B1C4(int, int*);
extern void fn_8035B120(int, int*);
extern void fn_8035A4FC(int);

void fn_8038AE04(void* self) {
    int locals[3];
    int i;
    int* ptr;
    void* temp;
    int temp2;

    if (*(int*)((char*)self + 0x7C) != 0) {
        fn_8035E00C(*(void**)((char*)self + 0x7C));
    }
    *(int*)((char*)self + 0x7C) = 0;
    *(int*)((char*)self + 0x80) = 0;
    if (*(int*)((char*)self + 0x6B4) != -1) {
        closesocket(*(int*)((char*)self + 0x6B4));
    }
    *(int*)((char*)self + 0x6B4) = -1;
    *(int*)((char*)self + 0x0) = 1;

    if (*(int*)((char*)self + 0x8) != 0) {
        i = 0;
        while (i < fn_8035A590(*(int*)((char*)self + 0x8))) {
            locals[2] = *(int*)fn_8035A598(*(int*)((char*)self + 0x8), i);
            temp = fn_8035B1C4(fn_80388590(self), &locals[2]);
            if (temp != 0) {
                temp2 = *(int*)((char*)temp + 4) - 1;
                *(int*)((char*)temp + 4) = temp2;
                if (temp2 == 0) {
                    fn_8035B120(fn_80388590(self), &locals[2]);
                }
            }
            i++;
        }
        fn_8035A4FC(*(int*)((char*)self + 0x8));
        *(int*)((char*)self + 0x8) = 0;
    }

    ptr = (int*)self;
    *(int*)((char*)self + 0x484) = -1;
    i = 0;
    while (i < *(int*)((char*)self + 0x480)) {
        locals[0] = ptr[0x21];
        temp = fn_8035B1C4(fn_80388590(self), &locals[0]);
        if (temp != 0) {
            temp2 = *(int*)((char*)temp + 4) - 1;
            *(int*)((char*)temp + 4) = temp2;
            if (temp2 == 0) {
                fn_8035B120(fn_80388590(self), &locals[0]);
            }
        }
        ptr++;
        i++;
    }
    *(int*)((char*)self + 0x480) = 0;
}
