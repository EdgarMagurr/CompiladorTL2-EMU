.386
.model flat, stdcall
option casemap:none
include \masm32\macros\macros.asm
include \masm32\include\masm32.inc
include \masm32\include\kernel32.inc
includelib \masm32\lib\masm32.lib
includelib \masm32\lib\kernel32.lib

.data
a dword 0
b dword 0
c dword 0

.code
main:
push 5
pop eax
mov a, eax
push 7
pop eax
mov b, eax
push a
push b
pop ebx
pop eax
add eax, ebx
push eax
pop eax
mov c, eax
ret
print str$(eax)
print chr$(10)
exit
end main
