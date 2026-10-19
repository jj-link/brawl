#pragma force_active on
extern "C" void fn_121_1AC4(void* self, int val);
extern "C" unsigned char lbl_121_data_8F94[];

extern "C" void* fn_121_12CA4(void* self, void* value) {
    fn_121_1AC4(self, 0);
    *(void**)self = lbl_121_data_8F94;
    *(void**)((char*)self + 8) = value;
    *(int*)((char*)self + 12) = -1;
    return self;
}
