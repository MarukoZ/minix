.sect .text
.extern	__chrt
.define	_chrt
.align 2

_chrt:
	jmp	__chrt

