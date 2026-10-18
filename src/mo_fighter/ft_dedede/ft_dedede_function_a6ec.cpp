#pragma force_active on
// fn_117_A6EC clears bits in a u32 array member of the work object.
// The original loads the array pointer from offset 0x1c (lwz r6,0x1c(r3)),
// scales the index by 4 (slwi r3,r5,2), then does
// arr[index] &= ~mask (lwzx, andc, stwx). The array's type and the member's
// name are not confirmed, so the pointer is accessed as a raw byte offset.
extern "C" void fn_117_A6EC(unsigned char* work, unsigned int mask, unsigned int index) {
    unsigned int* flags = *(unsigned int**)(work + 0x1c);
    flags[index] &= ~mask;
}
