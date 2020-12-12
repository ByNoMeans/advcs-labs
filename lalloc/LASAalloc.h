#pragma once
struct block {
    block* prev_;
    block* next_;
    size_t size_;
    void* allocated_;
};

class LASAalloc {
    void display_node(block* in_b);
    void* buffer_base = nullptr;
    size_t buffer_size_t = 0;
    block* free_list_b = nullptr;

public:
    LASAalloc();
    ~LASAalloc();
    void printFreeList();
    void* lalloc(size_t to_alloc);
    void* lfree(void* in_b);
    void* brk(size_t);
};