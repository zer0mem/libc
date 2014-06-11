IFDEF RAX

extrn _cc_alloc:near
extrn _cc_realloc:near
extrn _cc_free:near
extrn _cc_vsnprintf:near

.code

malloc proc
	jmp qword ptr _cc_alloc
malloc endp
             
realloc proc
	jmp qword ptr _cc_realloc
realloc endp

free proc
	jmp qword ptr _cc_free
free endp

vsnprintf proc
	jmp qword ptr _cc_vsnprintf
vsnprintf endp

ELSE
 .model flat
 
extrn __cc_alloc:near
extrn __cc_realloc:near
extrn __cc_free:near
extrn __cc_vsnprintf:near

.code

_malloc proc
	jmp dword ptr __cc_alloc
_malloc endp
             
_realloc proc
	jmp dword ptr __cc_realloc
_realloc endp

_free proc
	jmp dword ptr __cc_free
_free endp

_vsnprintf proc
	jmp dword ptr __cc_vsnprintf
_vsnprintf endp

ENDIF

end
