#pragma force_active on
extern "C" int registSequence__14gfSceneManagerFv(void* this_ptr, void* sequence) {
    int count = *(int*)((char*)this_ptr + 0x274);
    *(int*)((char*)this_ptr + 0x274) = count + 1;
    *(void**)((char*)this_ptr + 0x1a8 + count * 4) = sequence;
    return count;
}
