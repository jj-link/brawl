// Runtime.PPCEABI.H/fn_803F0D4C.c
// Provenance: reconstructs build/RSBE01_02/asm/Runtime.PPCEABI.H/fn_803F0D4C.s
// (MSL operator delete[] for arrays with a destructor cookie). Behavior
// recovered from the target disassembly: a non-null block with a non-null
// element destructor walks the array in reverse -- the cookie at block-0x10
// holds the element size and block-0xc the element count; the end pointer is
// block + elemsize*count and each iteration steps back one element before
// invoking the destructor with the -1 flag -- then frees the cookie-adjusted
// storage via __dla__FPv. A null block returns immediately; a null destructor
// still runs the free.

extern void __dla__FPv(void*);

typedef void (*DtorProc)(void*, int);

void fn_803F0D4C(void* block, DtorProc destroy) {
    unsigned long i;
    unsigned long count;
    unsigned long elemsize;
    char* end;

    if (block != 0) {
        if (destroy != 0) {
            elemsize = *(unsigned long*) ((char*) block - 0x10);
            i = 0;
            count = *(unsigned long*) ((char*) block - 0xc);
            end = (char*) block + elemsize * count;
            for (; i < count; i++) {
                end -= elemsize;
                (*destroy)(end, -1);
            }
        }
        __dla__FPv((char*) block - 0x10);
    }
}
