#pragma force_active on
extern "C" {
int fn_800F2894(void*);
void exit__6gfTaskFv(void*);
void fn_1_6DB4(void*, void*);

int fn_2_ECF4(void* self) {
    void* ptr = *(void**)((unsigned char*)self + 0x188);
    if (fn_800F2894(ptr)) {
        exit__6gfTaskFv(ptr);
        *(void**)((unsigned char*)self + 0x188) = 0;
        fn_1_6DB4(*(void**)((unsigned char*)self + 0x40), *(void**)((unsigned char*)self + 0x18c));
        void* c = *(void**)((unsigned char*)*(void**)((unsigned char*)self + 0x40) + 8);
        *(unsigned char*)((unsigned char*)c + 0xc) = 0;
        return 0xe;
    }
    return *(int*)((unsigned char*)self + 0x238);
}
}
