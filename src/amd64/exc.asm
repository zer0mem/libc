IFDEF RAX
ELSE
 .model flat
ENDIF


.code

__EH_prolog proc
	ret
__EH_prolog endp

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
_purecall proc
ELSE
__purecall proc
ENDIF
	int 3
	ret
IFDEF RAX
_purecall endp
ELSE
__purecall endp
ENDIF

IFDEF RAX
__CxxFrameHandler3 proc
ELSE
___CxxFrameHandler3 proc
ENDIF
	int 3
	ret
IFDEF RAX
__CxxFrameHandler3 endp
ELSE
___CxxFrameHandler3 endp
ENDIF

end
