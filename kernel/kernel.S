[bits 32]
%define ERROR_CODE nop  ;某些中断会压入异常码，不需要做操作
%define ZERO push 0     ;另外一些异常不会压入异常码,需要手动压入一个4字节占位符

extern put_str  ;声明外部函数

section .data
intr_str db "interrupt occur!", 0xa, 0
global intr_entry_table
intr_entry_table:

%macro VECTOR 2
section .text
intr%1entry:
    %2
    push intr_str
    call put_str
    add esp, 4  ;跳过参数

    ;如果是从片上进入的中断，要向主从片都发送EOI
    mov al, 0x20
    out 0xa0, al    ;从片
    out 0x20, al    ;主片

    add esp, 4      ;跳过错误码
    iret

section .data
    dd intr%1entry  ;存储各中断入口程序地址 形成intr_entry_table 数组
%endmacro