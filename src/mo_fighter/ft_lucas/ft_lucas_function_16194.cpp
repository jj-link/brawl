#pragma force_active on
typedef struct { char data[0x40]; } Block_9228;

extern "C" {
extern const Block_9228 lbl_114_data_9228;

void fn_114_16194(void* out, const Block_9228* block)
{
    block = &lbl_114_data_9228;
    *(const Block_9228**)out = block;
}
}
