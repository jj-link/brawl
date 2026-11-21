#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern "C" void fn_8015C144(void*, void*);
extern "C" void fn_8015BFB4(void*, void*);

extern "C" void fn_8005C2B0(void* a) {
    char* self = (char*)a;
    void* curr18;
    void* next18;
    char* p18;
    char* p24;
    void* curr;
    void* nxt;
    char* pC;
    void* nxtC;
    void* currC;

    {
        void* node;
        void* next;
        void* inner;
        node = fn_8015C1B0(*(char**)(self + 0x24) + 0x10, 0);
        void* inext;
        while (node) {
            next = fn_8015C1B0(*(char**)(self + 0x24) + 0x10, node);
            inner = *(void**)((char*)node + 0x44);
            while (inner) {
                inext = *(void**)((char*)inner +
                                  *(unsigned short*)((char*)node + 0x4E) + 0x4);
                char* ic8 = *(char**)((char*)inner + 0xC8);
                fn_8015C144(ic8 + 0x44, inner);
                fn_8015C144(*(char**)(self + 0x30) + 0x10, inner);
                fn_8015BFB4(*(char**)(self + 0x30) + 0x4, inner);
                inner = inext;
            }
            node = next;
        }
    }

    {
        void* first;
        p24 = *(char**)(self + 0x24);
        if (p24) {
            first = fn_8015C1B0(p24 + 0x10, 0);
            if ((curr = first) != 0) {
                nxt = fn_8015C1B0(p24 + 0x10, first);
                while (curr) {
                    if (*(int*)((char*)curr + 0xC) == 3 &&
                        *(int*)((char*)curr + 0x10) == 0) {
                        char* c20 = *(char**)((char*)curr + 0x20);
                        fn_8015C144(c20 + 0xCC, curr);
                        fn_8015C144(p24 + 0x10, curr);
                        fn_8015BFB4(p24 + 0x4, curr);
                    }
                    curr = nxt;
                    nxt = fn_8015C1B0(p24 + 0x10, nxt);
                }
            }
        }
    }

    {
        void* first;
        p18 = *(char**)(self + 0x18);
        if (p18) {
            first = fn_8015C1B0(p18 + 0x10, 0);
            if ((curr18 = first) != 0) {
                next18 = fn_8015C1B0(p18 + 0x10, first);
                while (curr18) {
                    if (*(int*)((char*)curr18 + 0xC) == 3 &&
                        *(int*)((char*)curr18 + 0x10) == 0) {
                        char* cbc = *(char**)((char*)curr18 + 0xBC);
                        fn_8015C144(cbc + 0x30, curr18);
                        fn_8015C144(p18 + 0x10, curr18);
                        fn_8015BFB4(p18 + 0x4, curr18);
                    }
                    curr18 = next18;
                    next18 = fn_8015C1B0(p18 + 0x10, next18);
                }
            }
        }
    }

    {
        pC = *(char**)(self + 0xC);
        if (pC) {
            void* first = fn_8015C1B0(pC + 0x10, 0);
            currC = first;
            if (currC) {
                nxtC = fn_8015C1B0(pC + 0x10, first);
                while (currC) {
                    if (*(int*)((char*)currC + 0xC) == 3 &&
                        *(int*)((char*)currC + 0x10) == 0) {
                        char* c20 = *(char**)((char*)currC + 0x20);
                        int val40 = *(int*)((char*)currC + 0x40);
                        char* target =
                            *(char**)(c20 + 0x5018) + val40 * 0x1C + 0xC;
                        fn_8015C144(target, currC);
                        fn_8015C144(pC + 0x10, currC);
                        fn_8015BFB4(pC + 0x4, currC);
                    }
                    currC = nxtC;
                    nxtC = fn_8015C1B0(pC + 0x10, nxtC);
                }
            }
        }
    }
}
