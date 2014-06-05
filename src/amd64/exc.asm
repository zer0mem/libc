IFDEF RAX
ELSE
 .model flat
ENDIF

.code

_CxxThrowException proc
	int 3
	ret
_CxxThrowException endp

_wassert proc
	ret
_wassert endp

end
