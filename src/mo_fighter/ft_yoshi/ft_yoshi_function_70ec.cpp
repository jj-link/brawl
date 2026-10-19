#pragma force_active on
extern "C" {
void fn_27_19BFCC(void*, short);
void __dl__FPv(void*);
void* fn_95_70EC(void*, short);
}

void* fn_95_70EC(void* ptr, short flag) {
    if (ptr) {
        fn_27_19BFCC(ptr, -1);
        if (flag > 0) {
            __dl__FPv(ptr);
        }
    }
    return ptr;
}
