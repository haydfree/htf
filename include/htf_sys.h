#ifndef HTF_SYS_H
#define HTF_SYS_H

static inline void htf_write(long fd, const char * const buf, long count)
{
    __asm__ __volatile__ (
        "movq $1, %%rax\n\t"
        "movq %0, %%rdi\n\t"
        "movq %1, %%rsi\n\t"
        "movq %2, %%rdx\n\t"
        "syscall"
        :
        : "r"(fd), "r"(buf), "r"(count)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
}

static inline void htf_read(long fd, char * const buf, long count)
{
    __asm__ __volatile__ (
        "movq $0, %%rax\n\t"
        "movq %0, %%rdi\n\t"
        "movq %1, %%rsi\n\t"
        "movq %2, %%rdx\n\t"
        "syscall"
        :
        : "r"(fd), "r"(buf), "r"(count)
        : "%rax", "%rdi", "%rsi", "%rdx"
    );
}

static inline void htf_exit(long status)
{
    __asm__ __volatile__ (
        "movq $60, %%rax\n\t"
        "movq %0, %%rdi\n\t"
        "syscall"
        :
        : "r"(status)
        : "%rax", "%rdi"
    );
    __builtin_unreachable();
}

#define WRITE(fd, buf, count) htf_write(fd, buf, count)
#define READ(fd, buf, count) htf_read(fd, buf, count)
#define EXIT(status) htf_exit(status)

#endif
