IFDEF RAX

extrn _cc_alloc:near
extrn _cc_realloc:near
extrn _cc_free:near

.code

malloc proc
	mov rax, qword ptr _cc_alloc
	jmp qword ptr [rax]
malloc endp
             
realloc proc
	mov rax, qword ptr _cc_realloc
	jmp qword ptr [rax]
realloc endp

free proc
	mov rax, qword ptr _cc_free
	jmp qword ptr [rax]
free endp

ELSE
 .model flat
 
extrn __cc_alloc:near
extrn __cc_realloc:near
extrn __cc_free:near

.code

_malloc proc
	mov eax, dword ptr __cc_alloc
	jmp dword ptr [eax]
_malloc endp
             
_realloc proc
	mov eax, dword ptr __cc_realloc
	jmp dword ptr [eax]
_realloc endp

_free proc
	mov eax, dword ptr __cc_free
	jmp dword ptr [eax]
_free endp

ENDIF

end
