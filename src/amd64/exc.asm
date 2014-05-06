.code

_CxxThrowException proc
	int 3
	ret
_CxxThrowException endp

_wassert proc
	xor rax, rax
	ret
_wassert endp

end
