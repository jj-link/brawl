#pragma force_active on
struct Type_2AE114 {
    int unk0;
    int unk4;
    unsigned int unk8;
};

extern "C" unsigned char fn_27_2AE114(const Type_2AE114* this_) {
    return (this_->unk8 >> 25) & 1;
}
