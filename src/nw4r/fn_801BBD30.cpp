#pragma force_active on
extern "C" void fn_801BBF58(void* p);

extern "C" void* fn_801BBD30(void* self) {
    fn_801BBF58(self);
    *(int*)((char*)self + 0xC) = 0;
    return self;
}
