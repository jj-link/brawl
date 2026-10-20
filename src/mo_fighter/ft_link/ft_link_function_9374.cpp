#pragma force_active on
extern "C" {
void* fn_93_929C(void*, short);
void* fn_27_C74E8(void*, short);
void* fn_93_85C4(void*, short);

void* fn_93_9374(char* owner, short deleting) {
    if (owner) {
        short memberDeleting = -1;
        fn_93_929C(owner + 0x18654, memberDeleting);
        fn_27_C74E8(owner + 0x18644, memberDeleting);
        fn_93_85C4(owner, short(0));
        if (deleting > 0) operator delete(owner);
    }
    return owner;
}
}
