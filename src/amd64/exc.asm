IFDEF RAX
ELSE
 .model flat
ENDIF

.code

IFDEF RAX
__EH_prolog proc
	pop rax
	push rbp
	mov rbp, rsp
	jmp rax
__EH_prolog endp

__EH_prolog3_catch proc
	pop rax
	push rbp
	mov rbp, rsp
	jmp rax
__EH_prolog3_catch endp

__EH_epilog3 proc
	mov rsp, rbp
	pop rbp
	ret
__EH_epilog3 endp

__EH_epilog3_catch proc
	mov rsp, rbp
	pop rbp
	ret
__EH_epilog3_catch endp
ELSE
__EH_prolog proc
	pop eax
	push ebp
	mov ebp, esp
	jmp eax
__EH_prolog endp

__EH_prolog3_catch proc
	pop eax
	push ebp
	mov ebp, esp
	jmp eax
__EH_prolog3_catch endp

__EH_epilog3 proc
	mov esp, ebp
	pop ebp
	ret
__EH_epilog3 endp

__EH_epilog3_catch proc
	mov esp, ebp
	pop ebp
	ret
__EH_epilog3_catch endp
ENDIF

_wassert proc
	ret
_wassert endp

__InternalCxxFrameHandler proc
	int 3
	ret
__InternalCxxFrameHandler endp

__hypot proc
	ret
__hypot endp

__invalid_parameter proc
	ret
__invalid_parameter endp


IFDEF RAX
__CxxFrameHandler3 proc
__CxxThrowException proc
ELSE
___CxxFrameHandler3 proc
___CxxThrowException proc
ENDIF


	int 3
	ret

IFDEF RAX
__CxxThrowException endp
__CxxFrameHandler3 endp
ELSE
___CxxThrowException endp
___CxxFrameHandler3 endp
ENDIF

end
