; CC12 - GMV Cross C compiler (V 4.2)
; optimization: None
; Default Code generation: HCS12
* Compiler Default segment names
	SEGMENT	text
	SEGMENT	bss
	SEGMENT	data
	SEGMENT	rodata
	FILE	"C:/Users/oskarje/globals.c"

;     1 | short	shortint;
	SEGMENT	bss
_shortint:	RMB	$2
	EXPORT	_shortint	[r,2]

;     2 | long	longint;
_longint:	RMB	$4
	EXPORT	_longint	[r,4]

;     3 | int	jusint;
_jusint:	RMB	$2
	EXPORT	_jusint	[r,2]

;     4 | int	intvec[10];
_intvec:	RMB	$14
	EXPORT	_intvec	[r,20]

;     5 | struct {
;     6 | int	s1;
;     7 | char	s2;
;     8 | char	*s3;
;     9 | } komplex;
_komplex:	RMB	$5
	EXPORT	_komplex	[r,5]

