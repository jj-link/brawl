#pragma force_active on
extern "C" {
void* fn_110_1ACC(void*, short);
void* fn_110_1EAC(void*, short);
void* fn_110_1F48(void*, short);
void* fn_110_1E41C(void*, short);
void* fn_27_125E20(void*, short);
void __dl__FPv(void*);

void* fn_110_1E37C(void* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_110_1ACC((char*)owner + 0xB194, memberDeleting);
        fn_110_1EAC((char*)owner + 0xACDC, memberDeleting);
        fn_110_1F48((char*)owner + 0xACA0, memberDeleting);
        fn_110_1E41C((char*)owner + 0x194, memberDeleting);
        fn_27_125E20(owner, 0);
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
